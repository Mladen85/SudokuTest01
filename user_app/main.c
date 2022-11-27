#include <stdio.h>
//#include <stdlib.h>
#include "sudoku_defs.h"
#include "sudoku_File.h"
#include "sudoku_List.h"

int main(int argc, char* argv[])
{
    FILE *pFile_sudokuFile = NULL;
    List_Element_t *head = NULL, *p_NewElement = NULL;
    uint8 i = 0, j = 0, k = 0;

#if 1
    File_v_SafeDatOpen(&pFile_sudokuFile, "dat.txt", "r+");
    File_v_DatToList(pFile_sudokuFile, &head);

    //List_v_PrintList(head);
#else
    File_v_SafeDatOpen(&pFile_sudokuFile, "dat.txt", "a");

    //Create new dummy list to write to file
    p_NewElement = (List_Element_t *)malloc(sizeof(List_Element_t));
    p_NewElement->tableID = i + 1;
    for (j = 0; j < SUDOKU_NUM; j++)
    {
        for (k = 0; k < SUDOKU_NUM; k++)
        {
            p_NewElement->sudokuTable[j][k] = (j + k) % SUDOKU_NUM;
        }
    }
    p_NewElement->next = NULL;
    head = p_NewElement;
    p_NewElement = NULL;
    i++;

    //printf("created first new element\n");

    for (; i < 10; i++)
    {
        p_NewElement = (List_Element_t *)malloc(sizeof(List_Element_t));
        p_NewElement->tableID = i + 1;
        for (j = 0; j < SUDOKU_NUM; j++)
        {
            for (k = 0; k< SUDOKU_NUM; k++)
            {
                p_NewElement->sudokuTable[j][k] = (j + k) % SUDOKU_NUM;
            }
        }
        p_NewElement->next = NULL;
        //printf("created %d new element in for loop\n", i);
        
        List_v_AddToEndOfList(head, p_NewElement);
        p_NewElement = NULL;
    }
    //printf("created %d new element\n", i);
    //End of creating dummy list
#endif
    List_v_PrintList(head);
    File_v_ListToDat(pFile_sudokuFile, head);
    File_si32_SafeDatClose(&pFile_sudokuFile);

    return 0;
}