/* EE2310 Lab08. Blackjack
   106061146, Chen Jhao-Ting
   2017.11.20
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int readcard(int a, int points);		// function for read card and add	
int Blackjack(int ipoints);				// function for play Blackjack

int main()								// main function
{
	srand( time(NULL) );				// time = NULL

	int i, c1, points;			// i for 2~20, c1 for rand, points
	double bustednum = 0, Esum = 0, Pronum = 0;	
	unsigned int exp;					// experiment time until N

	printf("Points  E(hit)  % Busted\n");
	
	for (i = 2; i < 21; i++){			// from 2 to 21
		for (exp = 0; exp < N; exp++){	// exp from 0 to N-1
			c1 = rand() % 13 + 1;		// c1 == random from 1 to 13
			points = readcard(c1, i);	// points calculate from readcard
			if(points > 21){			// if busted
				bustednum = bustednum + 1;	// busted time +1 for % Busted
			}
			Esum += points;				// Esum for E(hits)
		}
		if(bustednum != 0){				// 0.00 to 0
			printf("%4d    %6.2lf   %6.2lf  \n", i, Esum/N, bustednum/N*100);
		}else{							// print i, E(hits), % Busted
			printf("%4d    %6.2lf        0 \n", i, Esum/N);
		}
		Esum = 0;
		bustednum = 0;					// variables return to 0 for next i
	}
	
	for(exp = 0; exp < N; exp++){		// Probability of getting 21	
		c1 = rand() % 13 + 1;			// get first random number
		points = readcard(c1, 0);		// get first point
		if(Blackjack(c1) == 1){			// if Blackjack point equal to 21
			Pronum = Pronum + 1;		// succeed time +1
		}
	}

	printf("\nProbability of getting 21 points is %.2lf%\n", Pronum/N*100);
										// print probability	
	return 0;

}

int readcard(int a, int points)		// readcard and calculate points function
{
	if((a > 1) && (a <= 10)){		// a from 2 to 10 is its face value
		points += a;				
	}
	else if(a > 10){				// a > 10 is 10
		points += 10;
	}
	else if(a == 1){				// a == 1 is 1 or 11
		if((points+11) > 21){		// if point+11 > 21 busted
			points += 1;			// then a = 1
		}else{						
			points += 11;			// then a = 11
		}	
	}
	return points;					// return points value
}

int Blackjack(int ipoints)			// Blackjack func input initial points
{
	int c1, points;					// random num and later point

	c1 = rand() % 13 + 1;
	points = readcard(c1, ipoints);	// calculate point by readcard function

	if(points < 21){				// if point < 21 then draw one more card
		return Blackjack(points);	
	}
	else if(points == 21){			// if point == 21 then win, return 1
		return 1;
	}
	else if(points > 21){			// if point > 21 then busted, return 0
		return 0;
	}
}
