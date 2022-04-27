// Q2 u106061146 陳兆廷
// Please write a function 'rotate' that takes an N-element integer array
//     A={ A[0], A[1], A[2], ..., A[N-2], A[N-1] }
// as an input parameter and rearrange it to get
//     A={ A[1], A[2], A[3], ..., A[N-1], A[0] }.
//
// Note that your function should be general enough to handle different N
// and A array.
//

#include <stdio.h>

#define N 10

void rotate(int A[N])
{
	int temp;
	int i;

	temp = A[0];
	for ( i=0 ; i<N-1 ; i++ ){
		A[i] = A[i+1];
	}
	A[N-1] = temp;
}

int main(void){
	int i;
	int A[N] = {1,2,3,4,5,6,7,8,9,10};
	rotate(A);
	
	for( i=0; i<N ; i++){
		printf(" %d ", A[i]);
	}
	printf("\n");
	return 0;
}

