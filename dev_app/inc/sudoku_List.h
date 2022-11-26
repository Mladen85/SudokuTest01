/*
 * sudoku_List.h
 *
 * 2020/01/02
 *
 * Declaration of functions to work with List
 *
 */

#ifndef __SUDOKULIST_H__
  #define __SUDOKULIST_H__

  #include "sudoku_types.h"



  List_Element_t *List_st_NewElement(uint8 **sudTable, uint32 n);


  List_Element_t *List_st_AddToBegining(List_Element_t **pp_st_addElement);


  void List_v_AddToEndOfList(List_Element_t *p_st_addElement);


  sint8 List_si8_AddToNthPlace(List_Element_t *firstElement, List_Element_t *newElement, int n);


  List_Element_t *List_st_FindNthElement(List_Element_t *firstElement, uint32 no);


  List_Element_t *List_st_LastElement(List_Element_t *firstElement);


  void List_v_PrintList(List_Element_t *firstElement);


  uint32 List_ui32_DeleteNthElement(uint32 n);


  void List_v_ClearList(void);



  extern void ShowSudokuTable(uint8 **sud_table);


#endif /* __SUDOKULIST_H__ */