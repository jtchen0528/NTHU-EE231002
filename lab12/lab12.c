/* EE2310 Lab12. GCD and LCM.
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

FACTOR *factorize(int N);			// four function as requested
FACTOR *GCD(FACTOR *A, FACTOR *B);
FACTOR *LCM(FACTOR *A, FACTOR *B);
void write(FACTOR *A);
FACTOR *reverse(FACTOR *A);			// a function to reverse linked list

int gcd=1, lcm=1;			// two variables to count the value of GCD, LCM

int main(int argc, char *argv[])
{
	int A, B;
	A = atoi(argv[1]);			// transfer 2 input characters into interger
	B = atoi(argv[2]);
	printf("A = ");
	write(factorize(A));		// factorize A and print out
	printf(" = %d\nB = ", A);
	write(factorize(B));		// factorize B and print out
	printf(" = %d\nGCD = ", B);
	write(GCD(factorize(A), factorize(B)));	// find factorized A and B's GCD
	printf(" = %d\nLCM = ", gcd);
	write(LCM(factorize(A), factorize(B)));	// find factorized A and B's LCM
	printf(" = %d\n", lcm);
}

FACTOR *factorize(int N)		// factorize function
{
	int i, j, multi, testprime, end=0, start = 1;
	FACTOR *first=NULL;			// linked list first node
	FACTOR *new;				// linked list new node
	
	new = malloc(sizeof(struct factor));	// give new node an address
	
	for (i=N-1; i>=2; i--){		// find the prime number from N-1 to 2
		if((N%i)==0){			// if it could be prime number
			for (testprime=2; (testprime<i)&&(start==1); testprime++){
				if(i%testprime==0){		// test if it is truly prime number
					start=0;	// if it is not stop the loop
				}
			}
			if(start == 1){		// if it is a prime number
				new->prime = i;		// assign the prime to new node
				multi = i;
				for (j=0; end==0; j++){	// calculate the power of the prime
					multi = i*multi;
					if((N%multi)!=0){
						end = 1;		
					}
				}
				end = 0;
				new->power = j;		// assign power to new node
				new->next = first;	// next node points to first
				first = new;		// first points to new
				new = malloc(sizeof(struct factor));// give new node address
			}
			start = 1;		// start return to 1 for next prime number
		}
	}
	return first;		// return the factorized N
}

void write(FACTOR *A){		// "print out the factorized number" function
	for(; A!=NULL; A=A->next){		// from A to A=NULL
		if(A->power>1){				// if power more than 1
			printf("%d^%d", A->prime, A->power);	// print
		}else{
			printf("%d", A->prime);	// if power is one, no " ^ "
		}
		if(A->next!=NULL){		// " * " between primes
			printf(" * ");	
		}
	}
}

FACTOR *GCD(FACTOR *A, FACTOR *B)		// function to find GCD
{
	int i;				// i for counting
	FACTOR *first = NULL;		// first node is NULL
	FACTOR *new, *test;			// new node for linked list
	test = B;			// a pointer to store original B
	new = malloc(sizeof(struct factor));	// give new node an address
	new->prime = 1;				// in case no GCD, then GCD is 1
	for(; A!=NULL; A=A->next){				// if A.prime == B.prime then
		for(B=test; B!=NULL; B=B->next){	// choose the larger power
			if(A->prime == B->prime){		// then store
				new = malloc(sizeof(struct factor));	// give address
				new->prime = A->prime;		// assign new node prime
				if(A->power<B->power){
					new->power = A->power;	// assign the larger power
				}else{
					new->power = B->power;
				}
				for(i=0; i<new->power; i++){	// calculate the gcd value
					gcd = gcd*new->prime;
				}
				new->next = first;			// new.next points to first
				first = new;				// first points to new
			}
		}
	}
	new = reverse(new);			// it's the reverse linked list so reverse
	return new;					// return the GCD in FACTOR mode
}

FACTOR *LCM(FACTOR *A, FACTOR *B)		// function to find LCM
{
	int i, print=1, small=9999999, big=1;	// print to check if it is ok
	FACTOR *first = NULL;				// small and big to find prime order
	FACTOR *new, *testA, *testB;		// testA testB to store original A, B
	
	testB = B;					// assign testA, testB
	testA = A;
	
	new = malloc(sizeof(struct factor));	// give new node an address
	
	for (; testA!=NULL; testA=testA->next){		// find the largest prime num
		for (testB=B; testB!=NULL; testB=testB->next){	// to end the search
			if(testB->prime>big){
				big = testB->prime;
			}
		}
		if(testA->prime>big){
			big = testA->prime;	
		}				// now big is the largest prime number in A and B
	}
	for(; print ==1; ){			// search until small prime is the large prime 
		for (testA=A; testA!=NULL; testA=testA->next){	// search the smallest
			if(testA->prime<small){						// prime num in A, B
				small = testA->prime;
			}
		}
		for (testB=B; testB!=NULL; testB=testB->next){
			if(testB->prime<small){
				small = testB->prime;
			}
		}
		new = malloc(sizeof(struct factor));	// give new node an address
		new->prime = small;				// assign the prime number in > order
		for(testA=A; testA!=NULL; testA=testA->next){	
			if(testA->prime==small){	// find the largest power between A,B
				new->power = testA->power;	// and make used prime not a prime
				testA->prime = 9999999;
			}
		}
		for(testB=B; testB!=NULL; testB=testB->next){
			if(testB->prime==small){
				if(testB->power>new->power){
					new->power = testB->power;
				}
				testB->prime = 9999999;
			}
		}								// now the power of prime is found
		for(i=0; i<new->power; i++){	// calculate the LCM value
			lcm = lcm*new->prime;
		}
		new->next = first;			// new.next points to first
		first = new;				// first points to new
		if(small == big){			// if found the largest prime then end
			print = 0;
		}
		small=999999;
	}
	new = reverse(new);	// reverse linked list since we found prime from small
	return new;			// return the linked list
}

FACTOR *reverse(FACTOR *A)	// reverse function to reverse linked list
{
	FACTOR *p1, *p2, *p3;
	p2 = NULL;
	for (p1=A; p1!=NULL; ){
		p3 = p1->next;
		p1->next = p2;
		p2 = p1;
		p1 = p3;
	}
	return p2;
}
