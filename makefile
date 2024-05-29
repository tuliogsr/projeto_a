CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${TARGET}: ${BUILD}/cadastro_usuario.o ${BUILD}/analise_oportuna.o ${BUILD}/alertas_preco.o ${BUILD}/classes_ativos.o ${BUILD}/Grafics.o ${BUILD}/Catalogo.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/cadastro_usuario.o ${BUILD}/analise_oportuna.o ${BUILD}/alertas_preco.o ${BUILD}/classes_ativos.o ${BUILD}/Grafics.o ${BUILD}/Catalogo.o ${BUILD}/main.o -o ${TARGET}

${BUILD}/Catalogo.o: ${INCLUDE}/mercado/Catalogo.hpp ${SRC}/mercado/Catalogo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/mercado/ -c ${SRC}/mercado/Catalogo.cpp -o ${BUILD}/Catalogo.o

${BUILD}/Grafics.o: ${INCLUDE}/usuario/cadastro_usuario.hpp ${INCLUDE}/usuario/Grafics.hpp ${SRC}/usuario/Grafics.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/usuario/ -c ${SRC}/usuario/Grafics.cpp -o ${BUILD}/Grafics.o

${BUILD}/classes_ativos.o: ${INCLUDE}/mercado/classes_ativos.hpp ${SRC}/mercado/classes_ativos.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/mercado/ -c ${SRC}/mercado/classes_ativos.cpp -o ${BUILD}/classes_ativos.o

${BUILD}/alertas_preco.o: ${INCLUDE}/usuario/cadastro_usuario.hpp ${INCLUDE}/usuario/alertas_preco.hpp ${SRC}/usuario/alertas_preco.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/usuario/ -c ${SRC}/usuario/alertas_preco.cpp -o ${BUILD}/alertas_preco.o

${BUILD}/analise_oportuna.o: ${INCLUDE}/mercado/analise_oportuna.hpp ${SRC}/mercado/analise_oportuna.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/mercado/ -c ${SRC}/mercado/analise_oportuna.cpp -o ${BUILD}/analise_oportuna.o

${BUILD}/cadastro_usuario.o: ${INCLUDE}/usuario/cadastro_usuario.hpp ${SRC}/usuario/cadastro_usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/usuario/ -c ${SRC}/usuario/cadastro_usuario.cpp -o ${BUILD}/cadastro_usuario.o

${BUILD}/main.o: ${INCLUDE}/usuario/cadastro_usuario.hpp ${INCLUDE}/mercado/analise_oportuna.hpp ${INCLUDE}/usuario/alertas_preco.hpp ${INCLUDE}/mercado/classes_ativos.hpp ${INCLUDE}/usuario/Grafics.hpp ${INCLUDE}/mercado/Catalogo.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/mercado/ -I ${INCLUDE}/usuario/ -c ${SRC}/main.cpp -o ${BUILD}/main.o


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

	