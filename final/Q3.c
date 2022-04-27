// Q3 u106061146 陳兆廷
// Please write a function that modifies the input string by changing
// every occurrence of "Lin" to "Hong".
// For examp, if we have
//
// char story[1000] = \
// "After Lin became a starter for the Knicks, the Associated Press \
// called Lin 'the most surprising story in the NBA'. Knicks fans \
// developed nicknames for him along with a new lexicon inspired by \
// his name, Lin. Most popular was the word Linsanity, the excitement \
// over the unheralded Lin. Time.com ran an article titled, 'It's \
// Official: Linsanity Is for Real'."
//
// Then after LinToHong(story) we have
//
// char story[1000] = \
// "After Hong became a starter for the Knicks, the Associated Press \
// called Hong 'the most surprising story in the NBA'. Knicks fans \
// developed nicknames for him along with a new lexicon inspired by \
// his name, Hong. Most popular was the word Hongsanity, the excitement \
// over the unheralded Hong. Time.com ran an article titled, 'It's \
// Official: Hongsanity Is for Real'."
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LinToHong(char *story)
{
	int i, j=0, len, k;				// len to store string lenth
	char Lin[4] = "Lin", test[4];	// for comparism

	len = strlen(story);			// get the lenth of story
	for (i=0; i<len-3; i++){			// from head to tail of story
		test[j] = story[i];			// get three char store in test
		test[j+1] = story[i+1];
		test[j+2] = story[i+2];
		test[j+3] = '\0';
		if(strcmp(Lin, test)==0){	// if test and Lin is the same
			story[i] = 'H';			// replace Lin to Hong
			story[i+1] = 'o';
			story[i+2] = 'n';
			len++;					// len++
			for (k=len; k>i+3; k--){	// shift each char behind i+2 right
				story[k] = story[k-1];
			}
			story[i+3] = 'g';
			i=i+3;
		}
	}
}
