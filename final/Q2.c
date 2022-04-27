// Q2 u106061146 陳兆廷
// Given an NxN int matrix A, please write a function to transpose matrix A.
//
// For example, if N=3 and
//     | a00 a01 a02 |                                 | a00 a10 a20 |
// A = | a10 a11 a12 |, then transpose(A) produces A = | a01 a11 a21 |.
//     | a20 a21 a22 |                                 | a02 a12 a22 |
//

#include <stdio.h>
#define N 10

void transpose(int A[N][N])		// transpose function
{
	int i, j, temp;				// i, j for counting, temp to store change
		
	for (i=0; i<N; i++){			// from i to N
		for (j=0; j<i; j++){		// from j to i-1, to transpose
			temp = A[i][j];		// change the value of A[i][j] and A[j][i]
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}
}
