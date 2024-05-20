CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${TARGET}: ${BUILD}/cadastro_usuario.o ${BUILD}/analise_oportuna.o ${BUILD}/alertas_preco.o ${BUILD}/classes_ativos.o ${BUILD}/Grafics.o ${BUILD}/Catalogo.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/cadastro_usuario.o ${BUILD}/analise_oportuna.o ${BUILD}/alertas_preco.o ${BUILD}/classes_ativos.o ${BUILD}/Grafics.o ${BUILD}/Catalogo.o ${BUILD}/main.o -o ${TARGET}

${BUILD}/Catalogo.o: ${INCLUDE}/Catalogo.hpp ${SRC}/Catalogo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/Catalogo.cpp -o ${BUILD}/Catalogo.o

${BUILD}/Grafics.o: ${INCLUDE}/Grafics.hpp ${SRC}/Grafics.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/Grafics.cpp -o ${BUILD}/Grafics.o

${BUILD}/classes_ativos.o: ${INCLUDE}/classes_ativos.hpp ${SRC}/classes_ativos.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/classes_ativos.cpp -o ${BUILD}/classes_ativos.o

${BUILD}/alertas_preco.o: ${INCLUDE}/alertas_preco.hpp ${SRC}/alertas_preco.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/alertas_preco.cpp -o ${BUILD}/alertas_preco.o

${BUILD}/analise_oportuna.o: ${INCLUDE}/analise_oportuna.hpp ${SRC}/analise_oportuna.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/analise_oportuna.cpp -o ${BUILD}/analise_oportuna.o

${BUILD}/cadastro_usuario.o: ${INCLUDE}/cadastro_usuario.hpp ${SRC}/cadastro_usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/cadastro_usuario.cpp -o ${BUILD}/cadastro_usuario.o

${BUILD}/main.o: ${INCLUDE}/cadastro_usuario.hpp ${INCLUDE}/analise_oportuna.hpp ${INCLUDE}/alertas_preco.hpp ${INCLUDE}/classes_ativos.hpp ${INCLUDE}/Grafics.hpp ${INCLUDE}/Catalogo.hpp main.cpp
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

	