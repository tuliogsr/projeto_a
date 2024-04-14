CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/historia1.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/historia1.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/historia1.o: ${INCLUDE}/historia1.hpp ${SRC}/historia1.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historia1.cpp -o ${BUILD}/historia1.o

${BUILD}/main.o: ${INCLUDE}/historia1.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o
