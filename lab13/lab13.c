/* EE2310 Lab13. String Encoding
   106061146, Chen Jhao-Ting
   2017,12,25
*/

#include <stdio.h>

int main(void)
{
	int i, j;										// two variables to count
	char ch, c1, cin[4] ,c[200]={0};		// variables to getchar
												// arrays to store coded data
	while((ch=getchar())!='\n'){				// ignore the 'begin'
	}

	while((ch=getchar())!='e'){					// get first char if not 'e'
		if(ch>=64){							// if seventh bit is 1
			ch -= 64;						// turn to 0
		}
		for(i=0; i<ch; i++){				// continuously get 4 encoded data
			for(j=0; j<4; j++){
				cin[j]=getchar();			// store to the small array
				if(cin[j]>=64){
					cin[j]-=64;				// if seventh bit is 1 turn to 0
				}
			}
			c[i] = (cin[0]<<2) + (cin[1]>>4);	// first bit calculation
			i++;
			c[i] = cin[1];					// second bit calculation
			c1 = cin[1] >> 4;
			c1 = c1 << 4;
			c[i] = c[i] - c1;
			c[i] = c[i] << 4;
			c[i] += (cin[2] >> 2);
			i++;
			c[i] = cin[2];					// third bit calculation
			c1 = cin[2] >> 2;
			c1 = c1 << 2;
			c[i] = c[i] - c1;
			c[i] = c[i] << 6;
			c[i] += cin[3];
		}
		c1 = getchar();						// ignore the '\n' in data
		for(i=0; i<ch; i++){
			printf("%c", c[i]);				// print the line
		}
	}
	return 0;
}
