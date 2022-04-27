#include <stdio.h>

#define ABC 4

int main (){
	int array[13] = {ABC*4, ABC*4};
	int i;

	for(i=0;i<13;i++){
		printf("%d", array[i]);
	}
	return 0;
}
