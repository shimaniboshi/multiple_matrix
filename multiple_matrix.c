#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"


int input_matrix_size(LPMATRIX matrix) {

	int rows, cols;
	int ret = 0;

	while (1) {
		printf("Rows: ");
		scanf("%d", &rows);
		printf("Columns: ");
		scanf("%d", &cols);
		if (rows < 1 || cols < 1) {
			puts("Invalid input: Please specify a number greater than 1.");
			continue;
		}
		break;
	}

	ret = initialize_matrix(matrix, rows, cols);
	return ret;
}



int set_matrix_element_from_keyboard(LPMATRIX matrix) {

	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			int num, ret;

			printf("M[%d][%d] = ", i, j);
			scanf("%d", &num);

			if ((ret = set_matrix_element(matrix, i, j, num)) != 0) {
				return ret;
			}
		}
	}
	return 0;
}



int main(void) {

	// Declare matrixes and pointers to them
	MATRIX matrix_a, *p_ma = &matrix_a;
	MATRIX matrix_b, *p_mb = &matrix_b;
	MATRIX matrix_c, *p_mc = &matrix_c;

	// Set NULL to pointers of the structures so that they can be cleaned up easily.
	p_ma->elements = NULL;
	p_mb->elements = NULL;
	p_mc->elements = NULL;

	// Return code
	int ret = 0;


	// Input & Initialization 
	puts("This program computes the product of matrixes A and B.");
	puts("Please specify the matrix dimension.");

	puts("About Matrix A");
	if ((ret = input_matrix_size(p_ma)) != 0) {
		return ret;
	}

	puts("About Matrix B");
	if ((ret = input_matrix_size(p_mb)) != 0) {
		goto FREE_MATRIX;
	}


	if (matrix_a.cols != matrix_b.rows) {
		puts("Invalid input: Unable to compute the product of matrixes due to the mismatch of dimension.");
		puts("THe number of columns in Matrix A must match that of rows in Matrix B.");
		ret = ERROR_ALGEBRA;
		goto FREE_MATRIX;
	}


	//Initialize Matrix C based on dimensions of matrixes A and B
	if ((ret = initialize_matrix(p_mc, p_ma->rows, p_mb->cols)) != 0){
		goto FREE_MATRIX;
	}


	//Input elements in each matrix
	puts("Input elements in Matrix A");
	if ((ret = set_matrix_element_from_keyboard(p_ma)) != 0) {
		goto FREE_MATRIX;
	}

	puts("Input elements in Matrix B");
	if ((ret = set_matrix_element_from_keyboard(p_mb)) != 0) {
		goto FREE_MATRIX;
	}


	//Compute the product
	if ((ret = multiple_matrixes(p_ma, p_mb, p_mc)) != 0) {
		goto FREE_MATRIX;
	}

	//Display
	printf("\n<------------------------------- Result ------------------------------->\n");
	puts("Content of Matrix A");
	display_matrix(p_ma);
	printf("\n");

	puts("Content of Matrix B");
	display_matrix(p_mb);
	printf("\n");

	puts("Content of Matrix C");
	display_matrix(p_mc);
	printf("\n");


FREE_MATRIX:

	//Clean up heap memory
	free_matrix(p_ma);
	free_matrix(p_mb);
	free_matrix(p_mc);

	return ret;
}
