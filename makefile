GEN_DIR=gen
XML=nasdaq_totalview_itch.xml
SCRIPT=itch_msg_to_c.py

FLAGS = -Wall -Wextra -Wconversion -Wshadow -Wundef -fno-common  -Wno-unused-parameter -Wno-type-limits
CC = cc $(if $(debug),-DDEBUG -g)
LD = cc

test : main.o itch.o
	$(LD) -o test -g main.o itch.o

main.o : main.c
	$(CC) -c main.c $(FLAGS)

gen : ${GEN_DIR}/${XML} ${GEN_DIR}/${SCRIPT}
	cd ${GEN_DIR} ; python ${SCRIPT} ${XML}


itch.o: type.h itch_s.h ${GEN_DIR}/*.h gen 
	$(CC) -c itch.c $(FLAGS) 


clean:
	rm -f ${GEN_DIR}/*.h
	rm -f *.o	
	rm -f test	
