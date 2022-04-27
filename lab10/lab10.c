/* ~ee2310 Lab10. College Admission
   106061146, Chen Jhao-Ting
   2017.12.04
*/

#include <stdio.h>

typedef enum sDEPT {
	mathD, physD, chemD, geosD, none,
} DEPT;

typedef struct sStu {
	int appNum;
	char fName[20];
	char lName[20];
	int math, phys, chem;
	int total;
	DEPT pris[4];
	DEPT dept;
} Stu;

Stu s[100];				// an array of structure to store students
int Math=0, Phys=0, Geos=0, Chem=0;
int Mathmin, Physmin, Geosmin, Chemmin;

void read(void);		// function to read the data
void devide(int i);		// function ro devide students into their department
int math(int i);		// functions to put students into array of departments
int phys(int i);
int chem(int i);
int geos(int i);

int main(void)
{
	int i, j, k, score=0, snum, scorehigh=300;	// variables for .total order

	read();				// read the data
	
	for (j=0; j<100; j++){		// from the highest score student to devide
		for (i=0; i<100; i++){
			if((s[i].total>score)&&(s[i].total<scorehigh)){
				score = s[i].total;
				snum = i;
			}
		}
		for (i=snum+1; i<100; i++){	// if the same score, use appNum's order
			if(s[i].total==score){
				devide(i);		// go to devide
				j++;
			}
		}
		scorehigh = score;
		score = 0;
		devide(snum);			// go to devide
	}

	printf("\nMath Department: Minimum score %d\n", Mathmin);	// min score
	j=0;
	for (i=0;i<100;i++){			// find student in the department
		if(s[i].dept==0){
			j++;
			printf("%3d %d %s %s\n",j ,s[i].appNum, s[i].fName, s[i].lName);
		}
	}

	printf("\nPhys Department: Minimum score %d\n",Physmin);	// min score
	j=0;
	for (i=0;i<100;i++){
		if(s[i].dept==1){
			j++;
			printf("%3d %d %s %s\n",j ,s[i].appNum, s[i].fName, s[i].lName);
		}
	}
	
	printf("\nChem Department: Minimum score %d\n",Chemmin);	// min score
	j=0;
	for (i=0;i<100;i++){
		if(s[i].dept==2){
			j++;
			printf("%3d %d %s %s\n",j ,s[i].appNum, s[i].fName, s[i].lName);
		}
	}
	
	printf("\nGeos Department: Minimum score %d\n",Geosmin);	// min score
	j=0;
	for (i=0;i<100;i++){
		if(s[i].dept==3){
			j++;
			printf("%3d %d %s %s\n",j ,s[i].appNum, s[i].fName, s[i].lName);
		}
	}
	printf("\n");
}

void read(void)
{
	char c;
	char p[4][4];
	int i,j;
	
	while((c = getchar())!='\n');			// earase the first line

	for (i=0; i<100; i++){					// get all the data
		scanf("%d", &s[i].appNum);
		scanf("%s", &s[i].fName);
		scanf("%s", &s[i].lName);
		scanf("%d%d%d", &s[i].math, &s[i].phys, &s[i].chem);
		s[i].total = s[i].math+s[i].phys+s[i].chem;
		s[i].dept = 4;
		for (j=0; j<4; j++){
			scanf("%s", p[j]);
			switch (p[j][0]){
				case 'C' : s[i].pris[j] = chemD; break;
				case 'M' : s[i].pris[j] = mathD; break;
				case 'G' : s[i].pris[j] = geosD; break;
				case 'P' : s[i].pris[j] = physD; break;
			}
		}
	}
}

void devide(int i)		// devide function
{
	int j, end=0;
	for(j=0; (j<4)&&(end==0);j++){		// from pris 0 to 3
		switch(s[i].pris[j]){
			case 0: end = math(i); break;	// if result is yes, then end
			case 1: end = phys(i); break;
			case 2: end = chem(i); break;
			case 3: end = geos(i); break;
		}
	}
}

int math(int i)			// functions to put students in department
{
	if(Math<20){
		s[i].dept = 0;
		Math++;
		if(Math==20){
			Mathmin = s[i].total;
		}
		return 1;
	}
	return 0;				// failed then return 0
}

int phys(int i)			// functions to put students in department
{
	if(Phys<20){
		s[i].dept = 1;
		Phys++;
		if(Phys==20){
			Physmin = s[i].total;
		}
		return 1;
	}
	return 0;				// failed then return 0
}

int chem(int i)			// functions to put students in department
{
	if(Chem<20){
		s[i].dept = 2;
		Chem++;
		if(Chem==20){
			Chemmin = s[i].total;
		}
		return 1;
	}
	return 0;				// failed then return 0
}

int geos(int i)			// functions to put students in department
{
	if(Geos<20){
		s[i].dept = 3;
		Geos++;
		if(Geos==20){
			Geosmin = s[i].total;
		}
		return 1;
	}
	return 0;				// failed then return 0
}
