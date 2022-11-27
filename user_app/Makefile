
################################################################
## Makefile is used to build project with library "libsudoku.a"
## and to run application
################################################################

################################################################
## LIBRARY
# Library path
LIB_DIR = ../dev_app

# Library include
INC_LIB_DIR = inc

# Library archive
LIB = sudoku
################################################################

################################################################
## APPLICATION
TARGET = sudoku_app

# Application source
SRC_APP = $(wildcard *.c)

# Application object
OBJ_APP_DIR = .
OBJ_APP = $(patsubst %,$(OBJ_APP_DIR)/%, $(SRC_APP:.c=.o))
################################################################

################################################################
# Defining compiler, compiler flags and linker flags
CC = gcc
#CFLAGS_APP = -Wall -std=gnu99 -I$(LIB_DIR)/$(INC_LIB_DIR)
CFLAGS_APP = -Wall -std=gnu99 
#LFLAGS_APP = -l$(LIB) -L$(LIB_DIR)/$(INC_LIB_DIR)
LFLAGS_APP = 
################################################################

################################################################
## make application
$(TARGET) : $(OBJ_APP)
	$(CC) $(LFLAGS_APP) -o $@ $^

$(OBJ_APP_DIR)/%.o : %.c
	$(CC) $(CFLAGS_APP) -c $< -o $@
################################################################

.PHONY : run all clean help

# Run program
run : all
	./$(TARGET)

# Build project
all : $(TARGET)

# Clean program
clean :
	$(RM) $(TARGET) $(OBJ_APP)


help :
	@echo "inc_lib: $(LIB_DIR)/$(INC_LIB_DIR)"
	@echo "src_app: $(SRC_APP)"
	@echo "obj_app: $(OBJ_APP)"