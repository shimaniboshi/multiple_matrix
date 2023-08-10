#ifndef MATRIX_H
#define MATRIX_H

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------
#define ERROR_MEMORY -1
#define ERROR_ALGEBRA -2
#define ERROR_OUT_OF_INDEX -3



//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

typedef struct Matrix {
	int rows;
	int cols;
	int* elements;
} MATRIX, * LPMATRIX;


//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------


int initialize_matrix(LPMATRIX matrix, int rows, int cols);


void free_matrix(LPMATRIX matrix);


int get_matrix_element(const LPMATRIX matrix, int row, int col);


int set_matrix_element(LPMATRIX matrix, int row, int col, int value);


int multiple_matrixes(const LPMATRIX a, const LPMATRIX b, LPMATRIX c);


void display_matrix(const LPMATRIX matrix);




//-----------------------------------------------------------------------------
#endif
