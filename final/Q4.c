// Q4 u106061146 陳兆廷
// Suppose two positive integers, Na and Nb, have been factorized into
// linked lists, Fa and Fb, of prime factors using the structure below.
// Please write a function, FBnA, that returns a new linked list
// of all the prime factors that divide Nb but not Na.
// Note that the power of the prime factors of the returned linked list
// should all be 1. Also that all linked lists of prime factors are
// ordered by the prime factors in ascending order.

#include <stdio.h>
#include <stdlib.h>

typedef struct factor {    // node for a prime factor and it's power
	int prime;             // prime factor
	int power;             // associated power
	struct factor *next;   // pointer for the next prime factor
} FACTOR;

FACTOR *FBnA(FACTOR *Fa,FACTOR *Fb)		// function *FBnA
{
	FACTOR *first = NULL;				// node for NULL
	FACTOR *new, *temp1, *temp2;	// new to store FBnA, temps to reverse
	int A[100], B[100];				// two arrays to store primes of A, B
	int i, j, test=1;				// i, j for counting, test to check BnA

	for (i=0; Fa!=NULL; i++, Fa=Fa->next){	// get A's prime
		A[i] = Fa->prime;
	}
	A[i] = '\0';
	for (i=0; Fb!=NULL; i++, Fb=Fb->next){	// get B's prime
		B[i] = Fb->prime;
	}
	B[i] = '\0';

	for (i=0; B[i]!='\0'; i++){		// search from B to end
		for (j=0; A[j]!='\0'; j++){	// test if both A and B
			if(A[j]==B[i]){			// then don't store in FBnA
				test = 0;
			}
		}
		if(test==1){				// if BnA
			new = malloc(sizeof(FACTOR));	// store prime in FBnA
			new->prime = B[i];
			new->power = 1;			// power = 1
			new->next = first;
			first = new;
		}
		test = 1;					// turn test back to 1
	}
	while(new!=NULL){				// reverse FBnA in ascending order
		temp2 = new->next;
		new->next = temp1;
		temp1 = new;
		new = temp2;
	}
	return temp1;			// return FBnA
}
