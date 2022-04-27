/*EE231002 Lab01 Currency Exchange
  106061146	, Chen Jhao Ting
  09/18
*/

#include <stdio.h>

int main(void){

	int hun, fif, twen, ten, fiv, two, one;		//decalre variables for bills
	int amount;									//declare variable for USD
	int remain;									//declare variable for remains

	printf("Enter USD amount: ");
	scanf("%d", &amount);						//read USD from users
	printf("To pay:\n");

	hun = amount/100;						//hundred dollars bill calculations
	remain = amount-100*hun;

	if ( hun != 0 ) {
		if ( hun == 1 ) {
			printf("  %d $100 bill\n", hun);
		} else {
			printf("  %d $100 bills\n", hun);
		}
	}
	
	fif = remain/50;						//fifty dollars bill calculations
	remain = remain-50*fif;

	if ( fif != 0 ) {
		if ( fif == 1 ) {
			printf("  %d $50 bill\n", fif);
		} else {
			printf("  %d $50 bills\n", fif);
		}
	}
	
	twen = remain/20;						//twenty dollars bill calculations
	remain = remain-20*twen;
 
	if ( twen != 0 ) {
		if ( twen == 1 ) {
			printf("  %d $20 bill\n", twen);
		} else {
			printf("  %d $20 bills\n", twen);
		}
	}

	ten = remain/10;							//ten dollars bill calculations
	remain = remain-10*ten;

	if ( ten != 0 ) {
		if ( ten == 1 ) {
			printf("  %d $10 bill\n", ten);
		} else {
			printf("  %d $10 bills\n", ten);
		}
	}

	fiv = remain/5;								//five dollars bill calculations
	remain = remain-5*fiv;

	if ( fiv != 0 ) {
		if ( fiv == 1 ) {
			printf("  %d $5 bill\n", fiv);
		} else {
			printf("  %d $5 bills\n", fiv);
		}
	}

	two = remain/2;								//two dollars bill calculations
	remain = remain-2*two;

	if ( two != 0 ) {
		if ( two == 1 ) {
			printf("  %d $2 bill\n", two);
		} else {
			printf("  %d $2 bills\n", two);
		}
	}

	one = remain;								//one dollar bills calculations

	if ( one != 0 ) {
		if ( one == 1 ) {
			printf("  %d $1 bill\n", one);
		} else {
			printf("  %d $1 bills\n", one);
		}
	}	
	
	return 0;

}
