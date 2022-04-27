// Q4 u106061146 陳兆廷
// Given two positive integers a and b, we say b divides a if (a % b ==0).
//
// Please write a C program to prompt for 2 integers, N1 and N2,
// and then print out all prime numbers, p, such that p divides both N1 and N2.
//
// Example program output:
// $ ./a.out
// Enter N1: 20349
// Enter N2: 5775
// Prime 1: 3
// Prime 2: 7
// Number of primes found: 2
//

#include <stdio.h>

int isprime(int n)
{
	int i;
	for(i = 2; i<n; i++){
		if( (n%i) == 0 ){
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	
	int N1, N2, large;
	int i;
	int num = 0;

	printf("Enter N1: ");
	scanf("%d", &N1);
	printf("Enter N2: ");
	scanf("%d", &N2);

	if(N1>N2){
		large = N1;
	}
	else{
		large = N2;
	}

	if( (N1%2) == 0 && (N2%2) == 0){
		num++;
		printf("Prime %d: 2\n", num);
	}
	for( i=3 ; i <= large ; i = i+2 ){
		if( (N1%i) == 0 && (N2%i) == 0 ){
			if(isprime(i) == 1){
				num++;
				printf("Prime %d: %d\n", num, i);
			}
		}
	}
	printf("Number of primes found: %d\n", num);
	return 0;
}
