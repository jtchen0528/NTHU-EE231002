/* EE231002 lab09. Word Processing
   106061146, Chen Jhao-Ting
   2017,11,27
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LSTR 5000

int readLine(char para[LSTR]);		// function to read paragraph
void leftAlign(char *para);			// function for left
void center(char *pata);			// function for center
void bothAlign(char *para);			// function for both
int N, wd;							// global variable for N and
									// total words in a paragraph
int main(int argc, char *argv[])	// main function
{
	char para[LSTR], mode;			// an array to store paragraph
									// a mode to choose l, c or both
	if(argc<3){						// if user type wrong arguments
		printf("Usage: ./a.out N mode < infile\n");
		exit(1);
	}
	
	N = atoi(argv[1]);				// N from string transfer to interger
	mode = argv[2][0];				// mode is what user type in

	while(readLine(para)==0){		// when readLine haven't met EOF
		switch(mode){				// choose mode
			case 'l': leftAlign(para); break;
			case 'c': center(para); break;
			case 'b': bothAlign(para); break;
		}
	}

	return 0;
}

int readLine(char para[LSTR])		// function readLine store para[] 
{									// and return 0 or 1 if EOF
	char ch;						// ch to getchar
	wd = 0;							// word in paragragh length
	while((ch=getchar())!='\n'){	// getchar until Enter
		para[wd] = ch;				// store ch into para
		if((para[wd-2]=='E')&&(para[wd-1]=='O')&&(para[wd]=='F')){
			wd = wd-4;				// if met EOF, return 1 and don't store
			return 1;
		}
		wd++;
	}
	return 0;						// else return 0
}

void leftAlign(char *para)			// function leftAlign
{
	int i=0, lettercount=0, found=0;	// i, lettercount to count letters
	char line[101];					// array line to store and print a line
	while((lettercount+N)<=wd){		// if not the last line
		for (i=0; i<=N; i++){		// from 0 to N (line limit)
			line[i] = para[lettercount+i];	// store para into line
		}
		for (i=N; (i>0)&&(found==0); i--){	// find the last ' '
			if(line[i]==' '){				
				found = 1;
				lettercount = lettercount+i;	// remember where to start
			}									// next line
			line[i]=' ';
		}
		found = 0;
		for (i=0; i<N; i++){		// print the line
			printf("%c", line[i]);
		}
		printf("\n");				// Enter
		lettercount++;				// lettercount++ for next word
	}
	for (i=lettercount; i<wd; i++){	// print the last line
		printf("%c", para[i]);
	}
	printf("\n");
}

void center(char *para)				// function fot center
{
	int i=0, lettercount=0, found=0, center;// center to calculate spaces
	char line[101];				
	while((lettercount+N)<=wd){		// same as leftAlign
		for (i=0; i<=N; i++){
			line[i] = para[lettercount+i];
		}
		for (i=N; (i>0)&&(found==0); i--){
			if(line[i]==' '){
				found = 1;
				lettercount = lettercount+i;
			}
			line[i]=' ';
			center = (N-i+1)/2;		// calculate spaces needed to get center
		}
		found = 0;
		for (i=N-1; i>=0; i--){
			if(i>=center){	
				line[i] = line[i-center];	// move rightward to get center
			}else{
				line[i] = ' ';		// ' ' on the right
			}
		}
		for (i=0; i<N; i++){		// print the line 
			printf("%c", line[i]);
		}
		printf("\n");
		lettercount++;
	}
	center = (N+lettercount-wd)/2;	// calculate space needed in front of 
	for (i=0; i<center; i++){		// the last line
		printf(" ");
	}
	for (i=lettercount; i<wd; i++){	// print the last line
		printf("%c", para[i]);
	}
	printf("\n");
}

void bothAlign(char *para)	// function for both Align
{
	int i=0, j, lettercount=0, found=0, spaceleft, spacenum=0;
	int spacein, spaceside, spacecount=0;
	// spaceleft is the number of spaces at the end of a line
	// spacenum is the number of spaces between the words in a line
	// spacein is how many words between two additional spaces
	// spaceside is each side add how many spaces
	char line[101];
	while((lettercount+N)<=wd){	// same as last two functions
		for (i=0; i<=N; i++){	
			line[i] = para[lettercount+i];
			if(line[i] == ' '){
				spacenum++;		// count the spacenum
			}
		}
		spacenum--;				// minus the last space, it will be gone
		for (i=N; (i>0)&&(found==0); i--){
			if(line[i]==' '){
				found = 1;
				lettercount = lettercount+i;
			}
			line[i]=' ';
			spaceleft = N-i;	// spaceleft
		}
		found = 0;
		spacein = spacenum/(spaceleft+1);	// spacein
		spaceside = spaceleft/2;	// spaceside (right side)
		for (i=N-spaceleft-1; spaceside>0; i--){	// from the right side
			if(line[i]==' '){				// count until the spacein
				spacecount++;
			}
			if((spacein+1)== spacecount){	// if the spacein == spacecount
				for(j=N-1; j>i; j--){
					line[j] = line[j-1];	// all move to the right till i
				}
				spaceside--;				// spaceside used one
				spacecount=0;				// count return to 0
			}
		}
		spaceside = spaceleft-spaceleft/2;	// left side = remain spaces
		for (i=0; spaceside>0; i++){	// from the right side
			if(line[i]==' '){
				spacecount++;
			}
			if((spacein+1)==spacecount){	// if spacein == spacecount
				for(j=N-1; j>i; j--){
					line[j] = line[j-1];	// all move to right till i
				}
				spaceside--;				// side used 1
				spacecount=0;				// count return to 0
			}
		}
		for (i=0; i<N; i++){			// print the line
			printf("%c", line[i]);
		}
		printf("\n");
		lettercount++;
		spacenum=0,	spaceleft=0, spaceside=0, spacein=0, spacecount=0;
	}
	
	for (i=lettercount; i<wd; i++){		// print the last line
		printf("%c", para[i]);
	}	
	printf("\n");
}
