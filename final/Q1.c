// Q1 u106061146 陳兆廷
// The following equation has been proven.
//
//   1       1       1             1
// ----- - ----- + ----- - .... = --- ( 1 - log(2) )
// 1*2*3   3*4*5   5*6*7           2
//
// The left side of the equation is an infinite series.
// Please write a C program to calculate log(2) to be accurate to the 9th
// place below decimal point. (Note, as usual, program efficiency is
// important.)

#include <stdio.h>

int main(void)
{
	double log2=0;				// a double to store log2
	double i;					// a double to calculate

	for (i=1; i*i*i<10000000000; i=i+4){		// from 1 to i^3<10^10
		log2 = log2 + 1/(i*(i+1)*(i+2));	// calculate log2
		log2 = log2 - 1/((i+2)*(i+3)*(i+4));	// calculate log2
	}
	log2 = 1-2*(log2);
	printf("log(2) = %.10g\n",log2);	// print log2
	return 0;
}
