/* EE231002 Lab04. Deciphering Roman Numerals
   106061146, Chen Jhoa-Ting
   2017,10,16
*/
#include<stdio.h>

int main(void){
	
	char c;						//a char to scan rapidly
	int c_I = 0, c_II = 0;		//two int to calculate if plus or minus
	int value = 0;				//total value

	printf("Input a Roman Numeral: ");	//basic input
	
	while ((c = getchar())!='\n') {	//continue getchar till 'Enter'
		c_I = c_II;				//the second int shift to the first
		switch(c){				//switch case for c
		case 'I':		
			c_II = 1;			//I = 1
			break;
		case 'V':
			c_II = 5;			//V = 5
			break;
		case 'X':
			c_II = 10;			//X = 10
			break;
		case 'L':
			c_II = 50;			//L = 50
			break;
		case 'C':
			c_II = 100;			//C = 100
			break;
		case 'D':
			c_II = 500;			//D = 500
			break;
		case 'M':
			c_II = 1000;		//M = 1000
			break;
		}
		if (c_II <= c_I){				//calculation
			value = value + c_I;		//if first int is larger than second
		} else {						//than add the first int
			value = value - c_I;		//if first int is smaller than first
		}								//than minus the first int
	}

	value = value + c_II;				//calculation (add the last)
	printf("The value is: %d\n", value);//Basic output
	
	return 0;
}
