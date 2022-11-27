#include <stdio.h>
//#include <stdlib.h>
#include "sudoku_defs.h"
#include "sudoku_File.h"
#include "sudoku_List.h"


// #if (SUDOKU_CONSOLE == STD_ON)
//   #define SUDOKU_MESSAGE_TYPE(msg_type) "%" # msg_type
	
//   #define SUDOKU_INFO_MESSAGE_FILE(msg_val) do\
//   											{\
// 												printf(#msg_val "\n\n");
// 											}\
// 											while(0)
	
//   #define SUDOKU_ERROR_MESSAGE_FILE_OPEN(error_type, error_val) do\
//   																{\
// 																  printf("Error! Can not open dat \"" SUDOKU_MESSAGE_TYPE(error_type) "\"\n", error_val);\
// 																}\
// 																while(0)

//   #define SUDOKU_ERROR_MESSAGE_REALLOC(error_type, error_val) do\
//   															  {\
// 																printf("Reallocation failed! (" SUDOKU_MESSAGE_TYPE(error_type) ")\n", (error_val));\
// 															  }\
// 															  while(0)
// #else
//   //TODO: add different type of realloc error message for GUI
// #endif
// 
// example of call
// SUDOKU_ERROR_MESSAGE_REALLOC(d, 1);
// 


//static FILE *pFile_sudokuFile = NULL;

//static List_Element_t *head = NULL;

//static List_Element_t *p_st_Element = NULL;

void File_v_SafeDatOpen(FILE **pFile_sudokuFile, char *pstr_dat_name, char *pstr_dat_mode)
{

	if ((*pFile_sudokuFile = fopen(pstr_dat_name, pstr_dat_mode)) == NULL)
	{
#if (SUDOKU_CONSOLE == STD_ON)
		printf("Error! Can not open dat %s\n", pstr_dat_name);
#endif
		exit(EXIT_FAILURE);
	}
	else
	{
		//Do nothing
		printf("FILE OPEN\n\n");
	}
}

sint32 File_si32_SafeDatClose(FILE **pFile_sudokuFile)
{
	sint32 si32_status = -1;
	if (*pFile_sudokuFile)
	{
		si32_status = fclose(*pFile_sudokuFile);
#if (SUDOKU_CONSOLE == STD_ON)
		printf("FILE CLOSED\n\n");
#endif
		*pFile_sudokuFile = NULL;
		//si32_status = 1;
	}
	else
	{
#if (SUDOKU_CONSOLE == STD_ON)
		printf("FILE CAN'T BE CLOSED\n\n");
#endif
	}

	return si32_status;
}

/// This function is not used, check again if it is needed
#if 0
void File_v_ReadFromDat(FILE *pFile_sudokuFile, uint8 *pui8_readDat)
{
	char c;
	uint32 ui32_index = 0, ui32_noSteps = 15;

	if (pFile_sudokuFile)
	{
		while ((c = fgetc(pFile_sudokuFile)) != '\n')
		{
			if (ui32_index % ui32_noSteps == 0)
			{ //saves time (do not call realloc function every time, reserve 15 spaces and later realloc to actual size)
				pui8_readDat = realloc(pui8_readDat, (ui32_index + ui32_noSteps) * sizeof(uint8));
				if (pui8_readDat == NULL)
				{
#if (SUDOKU_CONSOLE == STD_ON)
					printf("Reallocation failed! (%d)\n", 1);
#endif
					exit(1);
				}
				else
				{
					//Do nothing
				}
			}
			pui8_readDat[ui32_index++] = c;
		}
	}
	else
	{
		//Do nothing
	}

	//realloc to actual size (remove )
	pui8_readDat = realloc(pui8_readDat, (ui32_index + 1) * sizeof(uint8));
	if (pui8_readDat == NULL)
	{
#if (SUDOKU_CONSOLE == STD_ON)
		printf("Reallocation failed! (%d)\n", 1);
#endif
		exit(1);
	}
	else
	{
		//Do nothing
	}

	pui8_readDat[ui32_index] = '\0';
}
#endif /* #if 0 */


/// This function is not used, check again if it is needed
#if 0
void DatToList(List_Element_t **pp_st_firstElement)
{
	uint32 ui32_Id = 0;
	char c;
	uint32 i = 0, j = 0;

	/*
	//Initialize sudokuTables
	sudTable = calloc(SUDOKU_NUM, sizeof(char*));
	for (i = 0; i < SUDOKU_NUM; i++) 
		sudTable[i] = calloc(SUDOKU_NUM, sizeof(char));
	*/

	p_st_Element = NULL;
	ui32_Id = 0;

	if (pFile_sudokuFile)
	{

		p_st_Element = malloc(sizeof(List_Element_t));

		while ((c = fgetc(pFile_sudokuFile)) != EOF)
		{

			//Initialize sudokuTables
			// p_st_Element->sudokuTable = calloc(SUDOKU_NUM, sizeof(char *));
			// for (i = 0; i < SUDOKU_NUM; i++)
			// {
			// 	p_st_Element->sudokuTable[i] = calloc(SUDOKU_NUM, sizeof(char));
			// }

			//Read sudoku table from dat
			for (i = 0; i < SUDOKU_NUM; i++)
			{
				j = 0;
				while ((c = fgetc(pFile_sudokuFile)) != '\n')
				{
					p_st_Element->sudokuTable[i][j] = c - 48; //Subtract 48 from ASCII (ASCII 49 - dec 1)
					j++;
				}
			}

			p_st_Element->tableID = ui32_Id;
			p_st_Element->next = NULL;

			ui32_Id++;

			if (*pp_st_firstElement == NULL)
			{
				*pp_st_firstElement = p_st_Element;
			}
			else
			{
				List_v_AddToEndOfList(head, p_st_Element);
			}
		}
	}
	else
	{
		//Do nothing
	}

	p_st_Element = NULL;
}
#endif /* #if 0 */

void File_v_DatToList(FILE *pFile_sudokuFile, List_Element_t **head)
{
	// List_Element_t *newElement = NULL;
	List_Element_t *p_st_Element = NULL;
	// uint8 **ui8_sudTable;
	uint32 ui32_Id = 0;
	char c;
	uint32 i = 0, j = 0;

	/*
	//Initialize sudokuTables
	ui8_sudTable = calloc(SUDOKU_NUM, sizeof(char*));
	for (i = 0; i < SUDOKU_NUM; i++) 
		ui8_sudTable[i] = calloc(SUDOKU_NUM, sizeof(char));
	*/

	ui32_Id = 0;

	if (pFile_sudokuFile)
	{
		printf("Start reading file!\n");
		while ((c = fgetc(pFile_sudokuFile)) != EOF)
		{
			printf("Char c = %d read! ",c);
			p_st_Element = NULL;
			p_st_Element = (List_Element_t *)malloc(sizeof(List_Element_t));

			//Initialize sudokuTables
			// p_st_Element->sudokuTable = calloc(SUDOKU_NUM, sizeof(uint8 *));
			// for (i = 0; i < SUDOKU_NUM; i++)
			// {
			// 	p_st_Element->sudokuTable[i] = calloc(SUDOKU_NUM, sizeof(uint8));
			// }

			//Read sudoku table from dat
			for (i = 0; i < SUDOKU_NUM; i++)
			{
				j = 0;
				//while ((c = fgetc(pFile_sudokuFile)) != '\n')
				while( (c != '\n') && (c != 'E'))
				{
					c = fgetc(pFile_sudokuFile);
					p_st_Element->sudokuTable[i][j] = c - 48; // Subtract 48 from ASCII (ASCII 49 - dec 1)
					j++;
				}
			}

			p_st_Element->tableID = ui32_Id;
			p_st_Element->next = NULL;

			ui32_Id++;
			printf("%d times\n", ui32_Id);

			if (*head == NULL)
			{
				*head = p_st_Element;
			}
			else
			{
				List_v_AddToEndOfList(*head, p_st_Element);
			}
		}
	}
	else
	{
		//Do nothing
	}

	p_st_Element = NULL;
}

void File_v_ListToDat(FILE *pFile_sudokuFile, List_Element_t *head)
{
	List_Element_t *p_st_Element = NULL;
	uint32 i = 0, j = 0;
	
	p_st_Element = head;
	if(pFile_sudokuFile)
	{
		while (p_st_Element)
		{
			fprintf(pFile_sudokuFile, "\n");
			for (i = 0; i < SUDOKU_NUM; i++)
			{
				for (j = 0; j < SUDOKU_NUM; j++)
				{
					fprintf(pFile_sudokuFile, "%d", p_st_Element->sudokuTable[i][j]);
				}
				fprintf(pFile_sudokuFile, "\n");
			}

			p_st_Element = p_st_Element->next;
		}
	}
	else
	{
		//Do nothing
	}
	//fprintf(pFile_sudokuFile, "E");
}


// #ifdef SUDOKU_MESSAGE_TYPE(msg_type)
//   #undef SUDOKU_MESSAGE_TYPE(msg_type)
// #endif

// #ifdef SUDOKU_INFO_MESSAGE_FILE(msg_val)
//   #undef SUDOKU_INFO_MESSAGE_FILE(msg_val)
// #endif

// #ifdef SUDOKU_ERROR_MESSAGE_FILE_OPEN(error_type, error_val)
//   #define SUDOKU_ERROR_MESSAGE_FILE_OPEN(error_type, error_val)
// #endif

// #ifdef SUDOKU_ERROR_MESSAGE_REALLOC(error_type, error_val)
//   #undef SUDOKU_ERROR_MESSAGE_REALLOC(error_type, error_val)
// #endif