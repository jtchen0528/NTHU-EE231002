/* EE2310 Lab05. Permutations
   106061146, Chen Jhao-Ting
   2017,10,23
*/

#include<stdio.h>
#define N 4

int main(void)
{
	int A[N];				//array A
	int num = 1 , n;		//num = # 1 2 3 ... n = n!(end while)
	int i , j , k;			//j,k for algorithm, i for loop count
	int stop = 0 , swap;	//stop to stop loop, swap to swap A[i]

	for (i = 0 ; i < N ; i++) {		//assign A[N]={N,N-1n...,2,1}
		A[i] = N-i;
	}
	printf("permutations #%d:", num);		//print the first per
	for( i = 0 ; i < N ; i++) {
		printf(" %d",A[i]);
	}
	num++;							//#++
	n = N;							//count n! for loop to stop
	for (i = n-1 ; i>0 ; i--) {
		n = n*i;
	}
	printf("\n");				
	while (num <= n) {				//num > n!, end
		for (i = N-2 ; i >= 0 && stop == 0 ; i--) {	//find A[j] for algorithm
			if(A[i] > A[i+1]){		
				j = i;				//remember j
				stop = 1;			//stop loop
			}
		}
		stop = 0;					//next loop
		for (i = N-1 ; i > j && stop == 0 ; i--) {	//find A[k] for algorithm
			if(A[j] > A[i]){		
				k = i;			//remember k
				stop = 1;		//stop loop
			}
		}
		stop = 0;				//next loop
		swap = A[j];			//swap A[j] A[k]
		A[j] = A[k];
		A[k] = swap;
		for (i = 1 ; (i+j) <= (j+N)/2 ; i++) {	//reverse from A[j+1] to last
			swap = A[j+i];		
			A[j+i] = A[N-i];
			A[N-i] = swap;
		}
		printf("permutations #%d:",num);	//print 1 permutation
		for (i = 0 ; i <= N-1 ; i++) {		
			printf(" %d",A[i]);
		}
		printf("\n");
		num++;						//#++
	}

	return 0;
}
