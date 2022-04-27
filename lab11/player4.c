/* EE2310 Lab11. Blackjack Strategy
   106061146, Chen Jhao-Ting
   2017.12.11
*/

#include <stdio.h>
#include "card.h"
extern int step_display;
extern int Nhand;
char play4_name[7]="Jack";

int play4_bet_init(int credit);
int play4_hit_or_stand(const struct CARD mycard[], int Nmycard,
						const struct CARD dealercard[], int Ndealercard);
void play4_shuffle();
void play4_deal_one_card(const struct CARD cd);

int cardleft[13] = {Ndeck*4, Ndeck*4, Ndeck*4, Ndeck*4, Ndeck*4, Ndeck*4, 
					Ndeck*4, Ndeck*4, Ndeck*4, Ndeck*4, Ndeck*4, Ndeck*4,
					Ndeck*4};			// an array to count cards
int setbet = 0;

int play4_bet_init(int credit)			
{
	step_display=0;
	Nhand=5000;
	if(setbet==0){
		if(credit>=9000){// each bet is 3, in case no luck.
			setbet = 1;
			return 3;
		}else{
			if(credit>=1000){
				return 500;
			}else{
				return 100;
			}
		}
	}else{
		return 3;
	}
}

int play4_hit_or_stand(const struct CARD mycard[], int Nmycard,
						const struct CARD dealercard[], int Ndealercard)
{
	int i, points = 0, pointsd = 0;	// points in hand and points of dealer
	double  E, E2, sumcards=0,sumcards2=0, numcards=0; 
			// E is Expect of A=1, E2 is Expect of A=11

	for(i=0; i<13; i++){		// calculate E and E2;
		if(i>8){
			sumcards += cardleft[i]*10;		// card amount * value
			sumcards2 += cardleft[i]*10;
		}else{
			sumcards += cardleft[i]*(i+1);
			sumcards2 += cardleft[i]*(i+1);
		}
		numcards += cardleft[i];
	}
	E = sumcards/numcards;						// calculated E, E2
	E2 = sumcards2/numcards + cardleft[0]*10;

	
	pointsd = card_point_hard(dealercard[0]);	// points of dealer(A=11)
	
	// calculate the points in hand, and with A no more than 21
	
	if(with_ace(mycard, Nmycard)==1){	// if got ACE in hand
		for(i=0; i<Nmycard; i++){
			if(points<=11){
				points += card_point_hard(mycard[i]);
			}else{
				points += card_point_soft(mycard[i]);
			}
		}
		if(points>21){			// if more than 21, one A must be 1
			points = points - 10;
		}
	}else{								// no ACE in hand
		for(i=0; i<Nmycard; i++){	
			points += card_point_hard(mycard[i]);
		}
	}
	
	// choose stand or hit or double or surrender

	if(Nmycard == 2){					// if only 2 cards in hand
		if(with_ace(mycard, Nmycard)==1){	// if there's A in hand
			switch(points){
				case 12:				// choose response depend on 
					if(pointsd==6){		// points of dealer and points in hand
						return 2;
					}else{
						return 1;
					}
					break;
				case 13: case 14:
					if((pointsd>4)&&(pointsd<7)){
						return 2;
					}else{
						return 1;
					}
					break;
				case 15: case 16:
					if((pointsd>3)&&(pointsd<7)){
						return 2;
					}else{
						return 1;
					}
					break;
				case 17:
					if((pointsd>2)&&(pointsd<7)){
						return 2;
					}else{
						return 1;
					}
					break;
				case 18:
					if(pointsd>8){
						return 1;
					}else if((pointsd>2)&&(pointsd<7)){
						return 2;
					}else{
						return 0;
					}
					break;
				default: return 0; break;
			}
		}else{						// if no A in hand
			switch(points){
				case 4: case 5: case 6: case 7: case 8:
					return 1; break;
				case 9:
					if((pointsd>2)&&(pointsd<7)){
						return 2;
					}else{
						return 1;
					}
					break;
				case 10:
					if(pointsd<10){
						return 2;
					}else{
						return 1;
					}
					break;
				case 11:
					if(pointsd<11){
						return 2;
					}else{
						return 1;
					}
					break;
				case 12:
					if((pointsd>3)&&(pointsd<7)){
						return 0;
					}else{
						return 1;
					}
					break;
				case 13: case 14: case 15: case 16:
					if(pointsd<7){
						return 0;
					}else{
						return 1;
					}
					break;
				default: return 0; break;
			}
			
		}
	}else{						// 3 cards or more cards in hands
		if(points<=10){			// depends on E and points of dealer
			if((E2+10)<=21){	// and points in hand to choose response
				if((E2+10)>=19){
					return 2;
				}else{
					return 1;
				}
			}else{
				return 1;
			}
		}else if(points<=12){
			if(pointsd>6){
				if((E+points)<=21){
					return 1;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else if(points<=16){
			if(pointsd<6){
				if((points+E)<=21){
					return 1;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else if(points<=21){
			return 0;
		}
	}
}

void play4_shuffle()
{
	 int i;
	 for(i=0; i<13; i++){
	 	cardleft[i] = Ndeck*4;		// return the cardleft to initial
	 }
}

void play4_deal_one_card(const struct CARD cd)
{
	switch(cd.value){				// if a card is drawn, -1 the card amount
		case ACE:	cardleft[0] -= 1;
		case TWO: 	cardleft[1] -= 1;
		case THREE: cardleft[2] -= 1;
		case FOUR: 	cardleft[3] -= 1;
		case FIVE: 	cardleft[4] -= 1;
		case SIX: 	cardleft[5] -= 1;
		case SEVEN: cardleft[6] -= 1;
		case EIGHT: cardleft[7] -= 1;
		case NINE: 	cardleft[8] -= 1;
		case TEN: 	cardleft[9] -= 1;
		case JACK: 	cardleft[10] -= 1;
		case QUEEN: cardleft[11] -= 1;
		case KING: 	cardleft[12] -= 1;
	}
}
