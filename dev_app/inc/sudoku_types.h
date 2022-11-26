/*
 * sudoku_types.h
 *
 * 2019/12/8
 *
 * Define custom types for project
 *
 */


#ifndef __SUDOKUTYPES_H__
# define __SUDOKUTYPES_H__


#include "typedefs.h"


#define SUDOKU_NUM 9

#define SUDOKU_AREA 3

#define SHUFLE_NUM 3

#define MAXREPEAT 100


typedef struct element_t {
    uint32 tableID;
    uint8 sudokuTable[SUDOKU_NUM][SUDOKU_NUM];
    struct element_t *next;
} Element_t;

typedef Element_t List_Element_t;


#endif /* __SUDOKUTYPES_H__ */