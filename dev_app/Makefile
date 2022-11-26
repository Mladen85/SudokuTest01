
################################################################
## Makefile is used to build library "libsudoku.a",
## to build project with library "libsudoku.a"
## and to run application
################################################################

################################################################
## LIBRARY
# Library path
LIB_DIR = ../lib

# Library archive
LIB = sudoku
LIB_NAME = $(LIB_DIR)/lib$(LIB).a

# Library source
SRC_LIB_DIR = src
SRC_LIB = $(wildcard $(LIB_DIR)/$(SRC_LIB_DIR)/*.c)

# Library include
INC_LIB_DIR = inc

# Library object
OBJ_LIB_DIR = obj
OBJ_LIB = $(patsubst %,$(LIB_DIR)/$(OBJ_LIB_DIR)/%, $(notdir $(SRC_LIB:.c=.o)))
################################################################

################################################################
## APPLICATION
TARGET = sudoku_app

# Application source
SRC_APP = $(wildcard *.c)

# Application object
OBJ_APP_DIR = obj
OBJ_APP = $(patsubst %,$(OBJ_APP_DIR)/%, $(SRC_APP:.c=.o))
################################################################

################################################################
# Defining compiler, compiler flags and linker flags
CC = gcc
CFLAGS_LIB = -Wall -std=gnu99 -I$(LIB_DIR)/$(INC_LIB_DIR)
CFLAGS_APP = -Wall -std=gnu99 -I$(LIB_DIR)/$(INC_LIB_DIR)
LFLAGS_APP = -l$(LIB) -L$(LIB_DIR)
################################################################

## make application is first to put it as default make rule

################################################################
## make library
$(LIB_NAME) : $(OBJ_LIB)
	$(AR) cr $@ $^

$(LIB_DIR)/$(OBJ_LIB_DIR)/%.o : $(LIB_DIR)/$(SRC_LIB_DIR)/%.c
	$(CC) $(CFLAGS_LIB) -c $< -o $@
################################################################

################################################################
## make application
$(TARGET) : $(OBJ_APP) $(LIB_NAME)
	$(CC) $(LFLAGS_APP) -o $@ $^

$(OBJ_APP_DIR)/%.o : %.c
	$(CC) $(CFLAGS_APP) -c $< -o $@
################################################################


.PHONY : run all clean app_clean libs_build libs_clean help

# Run program
run : all
	./$(TARGET)

# Build project
all : $(TARGET)

# Clean program
clean : app_clean libs_clean

# Clean application
app_clean :
	$(RM) $(TARGET) $(OBJ_APP)

# Run library (build library)
libs_build : $(LIB_NAME)

# Clean library
libs_clean :
	$(RM) $(OBJ_LIB) $(LIB_NAME)


help :
	@echo "src_lib: $(SRC_LIB)"
	@echo "obj_lib: $(OBJ_LIB)"
	@echo "src_app: $(SRC_APP)"
	@echo "obj_app: $(OBJ_APP)"