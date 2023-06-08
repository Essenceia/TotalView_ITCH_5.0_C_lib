import xmltodict
import pprint
import sys
import math

# conf list
FLAT_STRUCT_H = "flat_struc.h"
ITCH_MSG_STRUCT_INNER_H = "itch_msg_struc_inner.h"
ITCH_MSG_STRUCT_HEAD_H = "itch_msg_struc_head.h"
ITCH_MSG_FILL_CASE_H = "itch_msg_fill_case.h"

SIG_PREFIX = "itch_"

CASE_S_PTR = "tv_itch_s"
CASE_D_PTR = "data"

def parse_valid(msg_name, msg_id, msg_len, struct_f, struct_head_f, case_f):
    #sig_name = SIG_PREFIX + msg_name + "_v_o"
    sig_name = SIG_PREFIX + msg_name + "_v"
    inst_name = SIG_PREFIX + msg_name + "_data"
    sig_type = "bool"
    db_check = "exp_len = "+str(int(msg_len)-1)
    # get the ascii code for the message type
    # msg_id_i = msg_id
    # exp_msg_cnt = math.ceil(int(msg_len)/MOLD_MSG_LEN)
    # sig_logic = "("+ITCH_msg_id_SIG + " == 'd"+str(msg_id_i)+") & ("+MOLD_MSG_CNT_SIG+" == 'd"+str(exp_msg_cnt)+")"

    #flat_f.write("\n"+sig_type+" "+sig_name+" : "+msg_len+",\n")
    struct_f.write("\nstruct {\n")
    struct_head_f.write(sig_type+" "+sig_name+" : 1;\n")
    case_f.write("\ncase '"+msg_id+"': \n"+ db_check+ ";\nmemcpy(&"+CASE_S_PTR+"."+inst_name +","+ CASE_D_PTR +","+str(int(msg_len)-1) +");\nbreak;\n ")
    return inst_name

def parse_field(msg_name, field, struct_f):
    f_name = field['@name']
    f_len  = field['@len']
    f_offset = field['@offset']
    f_type = field['@type']
    sig_name = ""
    if not( f_name == "message_type" ):
        sig_name = SIG_PREFIX+msg_name+"_"+f_name
        #sig_dim = "["+f_len+"*LEN-1:0]"
        #sig_logic = MOLD_MSG_DATA_SIG+"[LEN*"+f_offset+"+LEN*"+f_len+"-1:LEN*"+f_offset+"]"

        #port_f.write("output logic "+sig_dim+" "+sig_name+",\n")
        #assign_f.write("assign "+sig_name+" = "+sig_logic+";\n") 
        #tb_port_f.write("."+sig_name+"("+sig_name+"),\n")
        #tb_sig_f.write("logic "+sig_dim+" "+sig_name+";\n")
        
        #flat_f.write(f_type+" "+sig_name+" : "+f_len+",\n")
        struct_f.write(f_type+" "+sig_name+" : "+f_len+";\n")

    return sig_name

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
        inst_name = parse_valid(msg_name , msg_id, msg_len, struct_f, struct_head_f, case_f )
        # clear list
        for field in struct['Field']:
            #print(type(field))
            if type(field) is dict:
                parse_field(msg_name, field, struct_f)
            else:
                assert(0)
        # add end of struct
        struct_f.write("}"+inst_name+";\n")
    print("C code generated")

main()
