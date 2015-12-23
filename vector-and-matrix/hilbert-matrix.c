// by: Daniel Carlson
// on: Wed 03:10 am

#include "array.h"
#include <stdio.h>
#include <stdlib.h>

double **hilbert_matrix(int n){
	double **H;
	make_matrix(H, n, n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			H[i][j] = 1.0 / (1 + i + j);
			
	return H;
}

int main(void){
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	
	double **H = hilbert_matrix(n);
	
	/* outputting the hilbert matrix */
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j % 10 == 0 && j != 0)
				printf("\n");
			else{
				for(int i = 0; i < n; i++)
					for(int j = 0; j < n; j++)
						printf("%d ", H[i][j]);
			}
		}
	}
	
	/* free the memory */
	free_matrix(H);
	
	return 0;
}
	
