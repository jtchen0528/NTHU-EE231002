/*EE231002 Lab03. Balanced Prime Number
  106061146, Chen Jhao-Ting
  2017.10.07
*/
#include<stdio.h>

int main(void)
{
	int bpn = 1, pn_a = 100, pn_b = 101, pn_c = 105;//bal_prime_num,3 temp num	
	int pn, j, stop;								//find prime_num, varivables	

	while(bpn <= 1000){								//1000 bal_prime_numb
		for (pn = 3 ; bpn <= 1000 ; pn = pn + 2){	//find prime from 3, ++2
			stop = 0;								//a variable to stop loop
			if(pn_a<=10000){				//when prime numbers less than 10000
				for (j = 3 ; j < pn/2 && stop == 0 ; j = j + 2){//test from 3 to pn/2
					if ( pn%j == 0 ){								//wrong, not prime
						stop = 1;									//exit the loop
					} 
				} 
				if ( stop == 0 ){					//if find a new prime number
					pn_a = pn_b;				//three temporary prime number, a<b<c
					pn_b = pn_c;
					pn_c = pn;
					if ( pn_b == (pn_a + pn_c)/2){	//if prime_number_b is bal_prime_num
						if ( bpn <= 10 || bpn > 990 ){	//print from 1 to 10, 991 to 1000
							printf("Balanced Prime Number #%d: %d\n", bpn, pn_b);
						}
						bpn++;						//# of balanced_prime_number
					}
				}
			}
			if(pn_a<=1000000&&pn_a>10000){			//when prime number >10000
				for (j = 3 ; j < 1000 && stop == 0 ; j = j + 2){	//test from 3 to 1000
					if ( pn%j == 0 ){								//wrong, not prime num
						stop = 1;									//exit the loop
					} 
				} 
				if ( stop == 0 ){						//if find a new prime number
					pn_a = pn_b;						//three temp prime number, a<b<c
					pn_b = pn_c;
					pn_c = pn;
					if ( pn_b == (pn_a + pn_c)/2){	//if prime_num_b is the bal_prime_num
						if ( bpn <= 10 || bpn > 990 ){	//print from 1 to 10, 991 to 1000
							printf("Balanced Prime Number #%d: %d\n", bpn, pn_b);
						}
						bpn++;							//# of balanced_prime_number
					}
				}
			}
		}
	}
	return 0;
}
