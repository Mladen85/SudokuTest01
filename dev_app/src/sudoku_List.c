#include <stdio.h>
#include <stdlib.h>
#include "sudoku_List.h"
#include "sudoku_defs.h"


// #if (SUDOKU_CONSOLE == STD_ON)
//   #define SUDOKU_MESSAGE_TYPE(msg_type) "%" # msg_type
	
//   #define SUDOKU_INFO_MESSAGE_PRINT_LIST(msg_type, msg_val) do\
//                                                             {\
//                                                                 printf("\n\nSudoku table number: " SUDOKU_MESSAGE_TYPE(msg_type), msg_val);\
//                                                             }\
//                                                             while(0)
// #else
//   //TODO: add different type of realloc error message for GUI
// #endif



extern List_Element_t *head;


static List_Element_t *p_st_Element = NULL;


List_Element_t *List_st_NewElement(uint8 **pp_ui8_sudTable, uint32 ui32_Id)
{
    p_st_Element = calloc(1, sizeof(List_Element_t));
    p_st_Element->sudokuTable = pp_ui8_sudTable;
    p_st_Element->tableID = ui32_Id;
    p_st_Element->next = NULL;

    return p_st_Element;
}


List_Element_t *List_st_AddToBegining(List_Element_t **pp_st_addElement)
{
    (*pp_st_addElement)->next = head;

    return *pp_st_addElement;
}


void List_v_AddToEndOfList(List_Element_t *p_st_addElement)
{
    List_Element_t *p_st_currentElement = head;

    while (p_st_currentElement->next)
    {
        p_st_currentElement = p_st_currentElement->next;
    }
    p_st_currentElement->next = p_st_addElement;
}


///Function adds new element to n-th place. If n > no_elements returns -1 else returns 1
///If adding to begining of te list use function List_Element_t *AddToBegining(List_Element_t *addElement)
sint8 AddToNthPlace(List_Element_t *p_st_currentElement, List_Element_t *p_st_addElement, uint32 ui32_Id)
{
    uint32 ui32_index = 0;
    sint8 status = 0;

    for (ui32_index = 0; ui32_index < ui32_Id; ui32_index++)
    {
        if (NULL == p_st_currentElement)
        {
            return -1;
        }
        else
        {
            //Do nothing
        }
        p_st_currentElement = p_st_currentElement->next;
    }
    p_st_addElement->next = p_st_currentElement->next;
    p_st_currentElement->next = p_st_addElement;

    return 1;
}


//Returns nth element of list or NULL if element is not found
List_Element_t *FindNthElement(List_Element_t *current, uint32 no)
{
    uint32 i = 0;

    while (i < no)
    {
        if (!current->next)
        {
            return NULL;
        }
        else
        {
            //Do nothing
        }
        current = current->next;
        i++;
    }

    return current;
}


List_Element_t *LastElement(List_Element_t *current)
{
    while (current->next)
    {
        current = current->next;
    }

    return current;
}


void PrintList(List_Element_t *current)
{
    while (current)
    {
#if (SUDOKU_CONSOLE == STD_ON)
        printf("\n\nSudoku table number: %d", current->tableID + 1);
#endif
        ShowSudokuTable(current->sudokuTable);
        current = current->next;
    }
}


uint32 DeleteNthElement(uint32 n)
{
    List_Element_t *current = head, *previous = NULL;
    uint32 i = 0, j = -1;

    //If n = 0 delete head
    if (n == 0)
    {
        head = head->next;
        free(current);
        j = 1;
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (current == NULL)
            {
                return -1;
            }
            else
            {
                //Do nothing
            }
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        j = 1;
    }

    return j;
}


void ClearList(void)
{
    List_Element_t *current = NULL;

    while (head)
    {
        current = head;
        head = head->next;
        free(current);
        current = NULL;
    }
}



// #ifdef SUDOKU_INFO_MESSAGE_PRINT_LIST(msg_type, msg_val)
//   #undef SUDOKU_INFO_MESSAGE_PRINT_LIST(msg_type, msg_val)
// #endif