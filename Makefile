BIN     := GAL.c

SRC_DIR := src
INC_DIR := include
OBJ_DIR := build
EXT_DIR := external


$(BIN) : $(OBJ_DIR)/matrix.o $(OBJ_DIR)/row_reduction.o $(OBJ_DIR)/main.o $(OBJ_DIR)/fort.o
	gcc -o GAL.c $(OBJ_DIR)/main.o $(OBJ_DIR)/matrix.o $(OBJ_DIR)/row_reduction.o $(OBJ_DIR)/fort.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/matrix.h $(INC_DIR)/row_reduction.h $(EXT_DIR)/libfort/fort.h
	gcc -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/matrix.o: $(SRC_DIR)/matrix.c $(INC_DIR)/matrix.h
	gcc -c $(SRC_DIR)/matrix.c -o $(OBJ_DIR)/matrix.o 

$(OBJ_DIR)/row_reduction.o: $(SRC_DIR)/row_reduction.c $(INC_DIR)/matrix.h $(INC_DIR)/row_reduction.h
	gcc -c $(SRC_DIR)/row_reduction.c -o $(OBJ_DIR)/row_reduction.o

$(OBJ_DIR)/fort.o: $(EXT_DIR)/libfort/fort.c $(EXT_DIR)/libfort/fort.h 
	gcc -c $(EXT_DIR)/libfort/fort.c -o $(OBJ_DIR)/fort.o
