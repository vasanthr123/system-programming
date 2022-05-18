BIN =bin/
OBJ=obj/
SRC=src/
INC=include/
CFLAG=-o
OBJFLAG=-c

all: program

program : function
	
	g++ ${CFLAG} ${BIN}server ${SRC}server.cpp ${OBJ}func.o 
	g++ ${CFLAG} ${BIN}client ${OBJ}func.o ${SRC}client.cpp
function: 
	g++ ${OBJFLAG} ${CFLAG} ${OBJ}func.o ${SRC}func.cpp
clean:
	rm ${OBJ}func.o
	rm ${BIN}server.o
	rm ${OBJ}client.o
