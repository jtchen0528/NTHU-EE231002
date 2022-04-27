/*EE231002 Lab01 Purchasing Petroleum
  106061146 , Chen Jhao Ting
  09/18
*/

#include <stdio.h>

int main(void){
	
	int NT;
	float lit_TW, lit_US, gal_TW, gal_US;

	printf("Input NT amount: ");
	scanf("%d", &NT);
	lit_TW = NT/25.8;
	gal_TW = NT/25.8/3.785;
	lit_US = NT/30.08/3.161*3.785;
	gal_US = NT/30.08/3.161;
	printf("Petroleum bought in Taiwan: %f liters or %f gallons.\n", 
	lit_TW, gal_TW);
	printf("petroleum bought in us: %f liters or %f gallons.\n", 
	lit_US, gal_US);

	return 0;

}
