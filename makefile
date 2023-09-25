ifndef debug
#debug := 
endif

ifndef fpos
#fpos :=
endif

GEN_DIR=gen
XML=nasdaq_totalview_itch.xml
SCRIPT=itch_msg_to_c.py
RELEASE=release
INC=inc

FLAGS = -std=gnu99 -Wall -Wextra -Wconversion -Wshadow -Wundef -fno-common  -Wno-unused-parameter -Wno-type-limits -fpic
CC = cc $(if $(debug),-DDEBUG -DFPOS -g) $(if $(fpos),-DFPOS)
LD = cc

test : test.o file.o itch.o
	$(LD) -o test -g test.o file.o itch.o

test.o : test.c
	$(CC) -c test.c $(FLAGS)

file.o: gen_flag file.h file.c
	$(CC) -c file.c $(FLAGS)

gen_flag : ${GEN_DIR}/${XML} ${GEN_DIR}/${SCRIPT}
	cd ${GEN_DIR} ; python ${SCRIPT} ${XML}
	touch gen_flag


itch.o: type.h itch.h itch.c itch_s.h gen_flag 
	$(CC) -c itch.c $(FLAGS) 

lib: itch.o file.o
	ar rcs libitch.a itch.o file.o 

release: lib
	mkdir -p $(RELEASE)/$(INC)/$(GEN_DIR)
	cp libitch.a $(RELEASE)/.
	cp *.h $(RELEASE)/$(INC)
	cp $(GEN_DIR)/*.h $(RELEASE)/$(INC)/$(GEN_DIR)

clean:
	rm -f gen_flag
	rm -f ${GEN_DIR}/*.h
	rm -f *.o	
	rm -f *.a	
	rm -f vgcore.*
	rm -f test
	rm -fr $(RELEASE)
