/*************************************************************/
/* Lab 7  Excercise 2      Ringvorlesung AI                  */
/*                                                           */
/* Write a C program that performs a 2D convoltion operation */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>




/* Displays a 2D matrix A with r rows and c columns    */

void printMatrix(float **A, int r, int c);

/*  Calculates Convolution f*h           		      */
/*  Parameters:                                       */
/*       float **f        f_dim-by-f_dim Matrix       */
/*       float **h      h_dim-by-h_dim Filter Kernel  */
/*  Return:                                           */
/*        float **o     (f*h) o_dim-by-o_dim Matrix   */
/*        int *o_dim     output matrix dimension      */
/*        int status     1 or 0                       */

float **convolve2D( float **f, int f_dim, float **h, int h_dim, int *o_dim, int *status);

int main(void){
	
	/***********************/	
	/* Predefined matrix A */
	/***********************/
	float A_arr[5][5] = {
		{0,2,3,0,3},
		{4,0,8,3,0},
		{0,7,5,0,3},
		{8,0,5,6,2},
		{0,0,4,2,3}
		};
		
	float **A= (float **) malloc(5*sizeof(float *));


	A[0]=&A_arr[0][0];
	A[1]=&A_arr[1][0];
	A[2]=&A_arr[2][0];
	A[3]=&A_arr[3][0];
	A[4]=&A_arr[4][0];

	printMatrix(A, 5, 5);

	/*************************/	
	/* Predefined Kernel h_1 */
	/*************************/	
		
	float h_1_arr[4][4]={
		{2,1,-1,-2},
		{2,1,-1,-2},
		{2,1,-1,-2},
		{2,1,-1,-2}
	};

	float **h_1= (float **) malloc(4*sizeof(float *));
	for (int i=0; i < 4; i++) h_1[i]=&h_1_arr[i][0];	

	// Other Varibale 

	int out_dim;
	int ret;
	float **out;

	printf("Convoled Matrix:\n");

	out = convolve2D(A, 5, h_1, 4, &out_dim, &ret);


	if (ret) printMatrix(out,out_dim,out_dim);

	//schwachsinn
	free(A); A=NULL;
	free(h_1); h_1=NULL;
		

}

// Here please implement your functions


void printMatrix(float **A, int r, int c) {

	size_t i = 0;
	size_t j = 0;

	for(; i < r; i++){

		printf("[ ");

		for(; j < c; j++){

			printf("%.2f", *(*(A + i) + j));

			if (j != c - 1) printf(", ");

		}

		j = 0;

		printf("]\n");


	}

}

#define FAIL_CONVOLUTION *status=0; return NULL;

/*  Calculates Convolution f*h           		      */
/*  Parameters:                                       */
/*       float **f        f_dim-by-f_dim Matrix       */
/*       float **h      h_dim-by-h_dim Filter Kernel  */
/*  Return:                                           */
/*        float **o     (f*h) o_dim-by-o_dim Matrix   */
/*        int *o_dim     output matrix dimension      */
/*        int status     1 or 0                       */
float **convolve2D( float **f, int f_dim, float **h, int h_dim, int *o_dim, int *status){
	
	
	int outsum = 0;

	if (f_dim < h_dim){
		FAIL_CONVOLUTION
	}
	*o_dim = f_dim - h_dim + 1;
	
	
	//out
	float** out = (float**) malloc(sizeof(float*) * (*o_dim));
	for(size_t i = 0; i < *o_dim; i++) out[i] = (float*) malloc(sizeof(float) * (*o_dim));

	
	for(size_t j = 0; j < *o_dim; j++){
		
		for(size_t k = 0; k < *o_dim; k++){

			outsum = 0;

			for(size_t l = 0; l < h_dim; l++){

				for(size_t m = 0; m < h_dim; m++){

					outsum += f[j + l][k + m] * h[h_dim - 1 - l][h_dim - 1 - m];

				}

			}

			out[j][k] = outsum; 

		}

	}

	*status = 1;
	return out;

}

#undef FAIL_CONVOLUTION


