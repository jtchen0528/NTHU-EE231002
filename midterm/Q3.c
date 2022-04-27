// Q3 u106061146 陳兆廷
// The trigonometric sine function can be approximated by the infinite
// series as
//               x^3     x^5     x^7     x^9
// sin(x) = x - ----- + ----- - ----- + ----- -  ....
//                3!      5!      7!      9!
//
// please write a function that given an input x, it calculates sin(x)
// with an accuracy of 1e-7, which is defined as a macro eps.
//
// For example, sine(3.1415926/4) = 0.707107
//              sine(3.1415926/6) = 0.5
//
#include<stdio.h>

#define eps 1e-7

double sine(double x)
{	
	int i,j;
	long long int b;
	double a;
	double sum=0.0;
	double sinx=0.0;
	
	for( i=1 ; i<=10 ; i = i+2){
		a=1.0;
		b=1;
		for(j=1; j<=i;j++){
			a = a*x;
			b = b*j;

		}
		sum = a/b;
		if((i%4) == 1){
			sinx = sinx + sum;
		}
		if((i%4) == 3){
			sinx = sinx - sum;
		}
	}
	return sinx;
}
int main(){
	int i;
	double ans;
	double A; 
	A = (3.1415926/6);
	printf("%.7f", sine(A));
	
	return 0;
}
