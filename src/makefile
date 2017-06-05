# Compilador
CC = g++

# Flags de versao
C_VERSION = -std=c++11

# Arquivo principal
OBJ_FILE = main.cpp

# Arquivos auxiliares
AUX_FILES = 

# Flags do compilador
CC_FLAGS = -g -Wall

# Linkers do compilador
CC_LINKERS = 
ifeq ($(OS),Windows_NT)
	CC_LINKERS += -lmingw32 -L../bin -L../lib
endif
CC_LINKERS += -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2main

# Arquivo de saída
ifeq ($(OS),Windows_NT)
	OUT_FILE = ../bin/Crazy-balls.exe
else
	OUT_FILE = ../bin/Crazy-balls.out
endif

all:
	$(CC) $(C_VERSION) $(OBJ_FILE) $(AUX_FILES) $(CC_FLAGS) $(CC_LINKERS) -o $(OUT_FILE)

clean:
	rm $(OUT_FILE)

run:
	$(OUT_FILE)

