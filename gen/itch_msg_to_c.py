import xmltodict
import pprint
import sys
import math

# conf list
FLAT_STRUCT_H = "flat_struc.h"
ITCH_MSG_STRUCT_INNER_H = "itch_msg_struct_inner.h"
ITCH_MSG_STRUCT_HEAD_H = "itch_msg_struct_head.h"
ITCH_MSG_FILL_CASE_H = "itch_msg_fill_case.h"
ITCH_MSG_PRINT_TYPE_H = "itch_msg_print_type.h"
ITCH_MSG_PRINT_H = "itch_msg_print.h"
ITCH_ENUM_H = "itch_msg_enum.h"
ITCH_TB_PUT_INNER_H = "tb_itch_msg_put_inner.h"
ITCH_TB_PUT_HEAD_H  = "tb_itch_msg_put_head.h"
ITCH_TB_PUT_ARGS_HEAD_H = "tb_itch_msg_put_args_head.h"
ITCH_TB_PUT_ARGS_INNER_H = "tb_itch_msg_put_args_inner.h"

SIG_PREFIX = "itch_"

CASE_S_PTR = "itch_s"
CASE_D_PTR = "data"

PRINT_S_PRT = "itch_msg"

def parse_valid(msg_name, msg_id, msg_len, struct_f, struct_head_f, case_f, print_type_f, print_f, put_f, put_arg_f):
    #sig_name = SIG_PREFIX + msg_name + "_v_o"
    sig_name = SIG_PREFIX + msg_name + "_v"
    inst_name = SIG_PREFIX + msg_name + "_data"
    sig_type = "bool"
    db_check = "exp_len = "+str(int(msg_len)-1)
    struct_f.write("\nstruct {\n")
    struct_head_f.write(sig_type+" "+sig_name+";\n")
    put_arg_f.write(sig_name+",\n")
    case_f.write("\ncase '"+msg_id+"': \n"+ db_check+ ";\n"+ CASE_S_PTR+"->"+ sig_name +"=1;\nmemcpy(&"+CASE_S_PTR+"->"+inst_name +","+ CASE_D_PTR +","+str(int(msg_len)-1) +");\nbreak;\n ")
    print_type_f.write("if("+PRINT_S_PRT+"->"+sig_name+') printf("Message type : '+msg_name+'\\n");\n')
    print_f.write("if("+PRINT_S_PRT+"->"+sig_name+') { \nprintf("Message type : '+msg_name+'\\n");\n')
    
    put_f.write("tb_vpi_logic_put_1b(argv,"+CASE_S_PTR+"->"+sig_name+");\n")
    return inst_name

def parse_field(msg_name, field, struct_f,inst_name, print_f, put_f, put_arg_f):
    f_name = field['@name']
    f_len  = field['@len']
    f_offset = field['@offset']
    f_type = field['@type']
    sig_name = ""
    if not( f_name == "message_type" ):
        sig_name = SIG_PREFIX+msg_name+"_"+f_name
        struct_f.write(f_type+" "+sig_name+";\n")
        put_arg_f.write(sig_name+",\n")
        if f_type[0] != "e" :
            print_f.write("print_"+f_type+'("'+f_name+'",'+PRINT_S_PRT+"->"+inst_name+"."+sig_name+");\n")
            put_f.write("tb_vpi_logic_put_"+str(int(f_len)*8)+"b(argv,"+CASE_S_PTR+"->"+inst_name+"."+sig_name+");\n")
        else:
            print_f.write('print_char_t("'+f_name+'",'+PRINT_S_PRT+"->"+inst_name+"."+sig_name+");\n")
            put_f.write("tb_vpi_logic_put_8b(argv,"+CASE_S_PTR+"->"+inst_name+"."+sig_name+");\n")
    return sig_name

def parse_enum(enums, enum_f):
    for enum in enums:
        e_name = enum['@name']
        e_type = enum['@type']
        enum_f.write("typedef "+e_type+" "+e_name+";\n")

def main():
    # Parse args.
    assert(len(sys.argv) == 2);
    path = sys.argv[1]
    assert(type(path) is str)
    
    # Open XML file.
    with open(path, 'r', encoding='utf-8') as file:
        my_xml = file.read()
    
    # Open or create output files
    flat_f = open(FLAT_STRUCT_H,"w")
    struct_f      = open(ITCH_MSG_STRUCT_INNER_H,"w")
    struct_head_f = open(ITCH_MSG_STRUCT_HEAD_H,"w")
    case_f = open(ITCH_MSG_FILL_CASE_H,"w")
    print_type_f = open(ITCH_MSG_PRINT_TYPE_H,"w")
    print_f = open(ITCH_MSG_PRINT_H,"w")
    enum_f = open(ITCH_ENUM_H,"w")
    put_head_f = open(ITCH_TB_PUT_HEAD_H, "w") 
    put_inner_f = open(ITCH_TB_PUT_INNER_H, "w") 
    put_arg_head_f = open(ITCH_TB_PUT_ARGS_HEAD_H, "w") 
    put_arg_inner_f = open(ITCH_TB_PUT_ARGS_INNER_H, "w") 

    # Parse XML
    content = xmltodict.parse(my_xml)
    
    # declare empty list
    sig_v_arr = []
    sig_field_arr = []
    
    # Read Strucsts
    structs = content['Model']['Structs']['Struct']
    for struct in structs:
        msg_name=struct['@name']
        msg_id=struct['@id']
        msg_len=struct['@len']
        inst_name = parse_valid(msg_name , msg_id, msg_len, struct_f, struct_head_f, case_f, print_type_f, print_f, put_head_f, put_arg_head_f  )
        # clear list
        for field in struct['Field']:
            #print(type(field))
            if type(field) is dict:
                parse_field(msg_name, field,struct_f, inst_name, print_f, put_inner_f, put_arg_inner_f)
            else:
                assert(0)
        # add end of struct
        struct_f.write("}"+inst_name+";\n")
        print_f.write("}\n")
    parse_enum(content['Model']['Enums']['Enum'], enum_f)
    print("C code generated")

main()
