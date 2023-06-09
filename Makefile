GEN_DIR=gen
XML=nasdaq_totalview_itch.xml
SCRIPT=itch_msg_to_c.py


FLAGS = -std=gnu99 -Wall -Wextra -Wconversion -Wshadow -Wundef -fno-common  -Wno-unused-parameter -Wno-type-limits
CC = cc $(if $(debug),-DDEBUG -g)
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

clean:
	rm gen_flag
	rm -f ${GEN_DIR}/*.h
	rm -f *.o	
	rm -f *.a	
	rm -f test

