// Q1 u106061146 陳兆廷
// Given an integer array A[N] with N different positive numbers.
// Please write a program to find the number of elements less than
// a predefined number m.
//
// For example, if N=10, A[N]={7, 10, 9, 8, 5, 6, 1, 4, 3, 2} and m=5, then
//
// $ ./a.out
// A has 4 elements less than 5.
//
// Note that your program should be general enough to handle different N, m,
// and A array.
//

#include <stdio.h>

#define N 10
int A[N]={7, 10, 9, 8, 5, 6, 1, 4, 3, 2};
int m=5;

int main(void)
{
	int i;
	int lessthanm = 0;

	for ( i=0 ; i<N ; i++){
		if( A[i] < m ){
			lessthanm++;
		}
	}
	printf("A has %d elements less than %d.\n", lessthanm, m);
	
	return 0;

}
