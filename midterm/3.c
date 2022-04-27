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
#include<stdio.h>
#define N 15

double sine(double x){
	double tup, tdo, tmp = 0.0;
	int i, j;
	for(i=0; i<N; i++){
		tup = 1.0;
		tdo = 1.0;
		for(j=1; j<=i*2+1; j++){
			tup*=x;
			tdo*=j;
		}
		if(i%2){
			tmp -= tup/tdo;
		}
		else{
			tmp += tup/tdo;
		}
	}
	return tmp;
}

int main(){
	double n;
	scanf("%lf", &n);
	printf("%lf\n", sine(n));
}
