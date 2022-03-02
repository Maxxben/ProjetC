CXX = g++
SRC_CLIENT = ./source/client/sources/.c
OBJ_CLIENT = $(SRC_CLIENT:.cc=.o)
EXEC_CLIENT = ./exec/client

SRC_SERVER = ./source/server/sources/.c
OBJ_SERVER = $(SRC_SERVER:.cc=.o)
EXEC_SERVER = ./exec/server

CFLAGS = -g pkg-config --cflags
LFLAGS = -lconfig -pthread -rdynamic

client:
    @$(CXX) $(OBJ_CLIENT) $(CFLAGS) $(LFLAGS) -o $(EXEC_CLIENT)
    @echo "Generation de l'executable client"

server:
    @$(CXX) $(OBJ_SERVER) $(CFLAGS) $(LFLAGS) -o $(EXEC_SERVER) 
    @echo "Generation de l'executable serveur"

all:
    @$(CXX) $(OBJ_CLIENT) $(CFLAGS) $(LFLAGS) -o $(EXEC_CLIENT)
    @$(CXX) $(OBJ_SERVER) $(CFLAGS) $(LFLAGS) -o $(EXEC_SERVER)
    @echo "Generation des 2 executables"

.PHONY: clean
clean:
    @rm -rf $(EXEC_CLIENT) $(EXEC_SERVER)
    @echo "Suppression des executables"

.PHONY: doc
doc:
    doxygen
    @echo "Generation de la documentation avec doxygen"