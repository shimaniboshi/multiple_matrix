#include "matrix.h"

// *** Double definition ***
// Already defined in the header file.
//
//typedef struct Matrix {
//	int rows;
//	int cols;
//	int* elements;
//} MATRIX, * LPMATRIX;




int initialize_matrix(LPMATRIX matrix, int rows, int cols) {

	matrix->rows = rows;
	matrix->cols = cols;
	
	matrix->elements = (int*)malloc(matrix->cols * matrix->rows * sizeof(int));
	if (matrix->elements == NULL) {
		return ERROR_MEMORY;
	}

	memset(matrix->elements, 0, matrix->cols * matrix->rows * sizeof(int));

	return 0;
}



void free_matrix(LPMATRIX matrix) {
	free(matrix->elements);
	matrix->elements = NULL;
}


int get_matrix_element(const LPMATRIX matrix, int row, int col) {
	int offset = row * matrix->cols + col;
	return *(matrix->elements + offset);
}


int set_matrix_element(LPMATRIX matrix, int row, int col, int value) {

	if (matrix->rows < row || matrix->cols < col) {
		puts("Out of index");
		return ERROR_OUT_OF_INDEX;
	}

	int offset = row * matrix->cols + col;
	*(matrix->elements + offset) = value;

	return 0;
}



int multiple_matrixes(const LPMATRIX a, const LPMATRIX b, LPMATRIX c) {

	int ret, sum;

	if (a->cols != b->rows) {
		puts("Unable to multuple matrixes due to the mismatch between rows and cols.");
		return ERROR_ALGEBRA;
	}

	for (int i = 0; i < c->rows; i++) {
		for (int j = 0; j < c->cols; j++) {

			sum = 0;
			for (int dummy = 0; dummy < a->cols; dummy++) {
				sum += get_matrix_element(a, i, dummy) * get_matrix_element(b, dummy, j);
				if ((ret = set_matrix_element(c, i, j, sum)) != 0) {
					return ret;
				}
			}
		}
	}

	return 0;
}



void display_matrix(const LPMATRIX matrix) {
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			printf(" %3d ", get_matrix_element(matrix, i, j));
		}
		printf("\n");
	}
	printf("\n");
}
