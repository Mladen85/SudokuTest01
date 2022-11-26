/*
 * sudoku_File.h
 *
 * 2019/12/8
 *
 * Declaration of functions to work with File
 *
 */

#ifndef __SUDOKUFILE_H__
  #define __SUDOKUFILE_H__

  #include "sudoku_types.h"


  // extern FILE *pFile_sudokuFile;

  /*
   * dat_mode:
   *  "r" - Opens a file for reading. The file must exist
   *  "w" - Creates an empty file for writing.
   *  "a" - Appends to a file
   *  "r+" - Opens a file to update both reading and writing. The file must exist
   *  "w+" - Creates an empty file for both reading and writing
   *  "a+" - open for read and append text file
   * 
   */
  void File_v_SafeDatOpen(char *dat_name, char *dat_mode);


  sint32 File_si32_SafeDatClose(void);


  void File_v_ReadStringFromDat(uint8 *pui8_readDat);


  static void DatToList(List_Element_t **firstElement);


  void File_v_DatToList(List_Element_t **firstElement);


  void File_v_ListToDat(List_Element_t *firstElement);



  extern void List_v_AddToEndOfList(List_Element_t *addElement);


#endif /* __SUDOKUFILE_H__ */