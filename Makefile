SHELL := /bin/bash
# variáveis dos diretórios para facilitar a manutensão do código
SRC = ./src
BIN = ./bin
OBJ = ./obj
INCLUDE = ./include
# target principal que utilizará os target de objetos e aplicativo
all: libgi myapp
# target de objetos
libgi:
	@mkdir -p ./obj

	gcc -c ${SRC}/main.c -I ${INCLUDE} -o ${OBJ}/main.o
	gcc -c ${SRC}/verifystorage.c -I ${INCLUDE} -o ${OBJ}/verifystorage.o
	gcc -c ${SRC}/findprodmethods.c -I ${INCLUDE} -o ${OBJ}/findprodmethods.o
	gcc -c ${SRC}/listingprods.c -I ${INCLUDE} -o ${OBJ}/listingprods.o
	gcc -c ${SRC}/menu.c -I ${INCLUDE} -o ${OBJ}/menu.o
	gcc -c ${SRC}/overwrite.c -I ${INCLUDE} -o ${OBJ}/overwrite.o
	gcc -c ${SRC}/prodmanagement.c -I ${INCLUDE} -o ${OBJ}/prodmanagement.o
	gcc -c ${SRC}/sleep.c -I ${INCLUDE} -o ${OBJ}/sleep.o
# target aplicativo
myapp:
# cria o diretório bin caso não exista
	@mkdir -p ./bin
# compila o aplicativo em bin/(nome do aplicativo)
	gcc ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/Stocku
# target para executar o aplicativo
run:
	./bin/Stocku.exe
# target para limpar os executáveis e objetos gerados
clean:
	rm -f ./obj/*.o
	rm -f ./bin/Stocku.exe
	clear