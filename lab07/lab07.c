/* EE2310 lab07. Matrix Determinant
   106061146, Chen Jhao Ting
   2017.11.13
*/

#include <stdio.h>

#if !defined(N)
#define N 3
#endif

double det(double A[N][N], int dim);		// det func
void print(double A[N][N]);					// print func

int main(void)
{
	double mat[N][N] = {0};					// intitial matrix
	int i, j;

	for (i=0; i<N; i++){					// scanf matrix
		for (j=0; j<N; j++){
				scanf("%lf", &mat[i][j]);
		}
	}
	
	print(mat);								// print matrix

	printf("det(A) = %.0f\n", det(mat, N));	// print determinant

	return 0;
}

void print(double A[N][N])					// print func
{	
	int i, j;								
	printf("Matrix A is\n");		
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
				printf("%3.0f", A[i][j]);
		}
		printf("\n");
	}
}

double det(double A[N][N], int dim)			// find determinant func
{
	int row, col, i, j, irow = 0, sum = 0;	// variables for calculation
	double a[N][N] = {0};					// small matrix 

	if(dim == 2){							// return when small dim == 2	
		return (A[0][0]*A[1][1]-A[0][1]*A[1][0]);					
	}else{	
		for (row = 0; row < dim; row++){	// multiply row[0][0] to [dim][0]
			for (i = 0; i < dim-1; i++){	// create small maatrix
				if(irow != row){			// don't copy the same row 
					for (j = 0; j < dim-1; j++){
						a[i][j] = A[irow][j+1];	
					}						// irow is use to avoid same row
				}else{
					irow++;
					for (j = 0; j < dim-1; j++){
						a[i][j] = A[irow][j+1];
					}
				}
				irow++;
			}
			if(row%2 == 0){					// if row is even then add
				sum = sum + A[row][0]*det(a,dim-1);
			}
			if(row%2 == 1){					// if row is odd then minus 
				sum = sum - A[row][0]*det(a,dim-1);
			}
			irow = 0;						// recalculate irow
		}
		return sum;							// return sum
	}
}
