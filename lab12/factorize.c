/* EE2310 Lab12. factorize.
   106061146, Chen Jhao-Ting
   2017.12.18
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct factor {		// node for a prime factor
	int prime; 				// prime factor
	int power; 				// associated power
struct factor *next;	// pointer for the next prime
} FACTOR;

FACTOR *factorize(int N);
FACTOR *GCD(FACTOR *A, FACTOR *B);
FACTOR *LCM(FACTOR *A, FACTOR *B);
void write(FACTOR *A);

int main(int argc, char *argv[])
{
	int A, B;
	A = atoi(argv[1]);
	B = atoi(argv[2]);
	printf("A = ");
	write(factorize(A));
	printf(" = %d\nB = ", A);
	write(factorize(B));
	printf(" = %d\n", B);
}

FACTOR *factorize(int N)
{
	int i, j, multi, testprime, end=0, start = 1;; 
	FACTOR *first=NULL;
	FACTOR *new;
	new = malloc(sizeof(struct factor));
	for (i=N-1; i>=2; i--){
		if((N%i)==0){
			for(testprime=2; (testprime<i)&&(start==1); testprime++){
				if(i%testprime==0){
					start=0;
				}
			}
			if(start == 1){
				new->prime = i;
				multi = i;
				for(j=0; end==0; j++){
					multi = i*multi;
					if((N%multi)!=0){
						end = 1;
					}
				}
				end = 0;
				new->power = j;
				new->next = first;
				first = new;
				new = malloc(sizeof(struct factor));
			}
			start = 1;
		}
	}
	return first;
}

void write(FACTOR *A){
	for(; A!=NULL; A=A->next){
		if(A->power>1){
			printf("%d^%d", A->prime, A->power);
		}else{
			printf("%d", A->prime);
		}
		if(A->next!=NULL){
			printf(" * ");
		}
	}
}
