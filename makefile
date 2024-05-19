CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${TARGET}: ${BUILD}/cadastro_usuario.o ${BUILD}/historia5.o ${BUILD}/historia4.o ${BUILD}/historia3.o ${BUILD}/historia2.o ${BUILD}/historia1.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/cadastro_usuario.o ${BUILD}/historia5.o ${BUILD}/historia4.o ${BUILD}/historia3.o ${BUILD}/historia2.o ${BUILD}/historia1.o ${BUILD}/main.o -o ${TARGET}

${BUILD}/historia1.o: ${INCLUDE}/historia1.hpp ${SRC}/historia1.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historia1.cpp -o ${BUILD}/historia1.o

${BUILD}/historia2.o: ${INCLUDE}/historia2.hpp ${SRC}/historia2.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historia2.cpp -o ${BUILD}/historia2.o

${BUILD}/historia3.o: ${INCLUDE}/historia3.hpp ${SRC}/historia3.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historia3.cpp -o ${BUILD}/historia3.o

${BUILD}/historia4.o: ${INCLUDE}/historia4.hpp ${SRC}/historia4.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historia4.cpp -o ${BUILD}/historia4.o

${BUILD}/historia5.o: ${INCLUDE}/historia5.hpp ${SRC}/historia5.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historia5.cpp -o ${BUILD}/historia5.o

${BUILD}/cadastro_usuario.o: ${INCLUDE}/cadastro_usuario.hpp ${SRC}/cadastro_usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/cadastro_usuario.cpp -o ${BUILD}/cadastro_usuario.o

${BUILD}/main.o: ${INCLUDE}/cadastro_usuario.hpp ${INCLUDE}/historia5.hpp ${INCLUDE}/historia4.hpp ${INCLUDE}/historia3.hpp ${INCLUDE}/historia2.hpp ${INCLUDE}/historia1.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o


builder:
	if not exist build mkdir build
	if not exist build\bin mkdir build\bin

run:
	${BUILD}/${TARGET}

clean:
	del build\*.exe
	del build\bin\*.o

test:
	g++ -std=c++11 -Wall -g test.cpp -o progTeste
	.\progTeste.exe

cleanTest:
	del progTeste.exe