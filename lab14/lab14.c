/* EE2310 Lab14. Image Processing
   106061146, Chen Jhoa-Ting
   2017,12,29
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sPIXEL{		// a single pixel
	unsigned char r, g, b;	// three color components
} PIXEL;

typedef struct sIMG{		// an image of PPM style
	char header[3];			// header, either P3 or P6
	int W, H;				// width andheight of the image
	int level;				// intensity level of each color component
	PIXEL **PX;				// two-dimensional array for all the pixels
} IMG;

IMG *PPMin(char *inFile);		// function to read file
void *PPMout(IMG *p1, char *outFile);	// function to output file
IMG *PPMcvt(IMG *p1, IMG *ee, IMG *nthu);	// function to convert PPM

int main(int argc, char *argv[])	// main function with 4 arguments(files)
{
	IMG *p1,* ee, *nthu;		// three IMG PPM

	p1 = PPMin(argv[1]);		// p1, ee, nthu read into IMG format
	ee = PPMin(argv[2]);
	nthu = PPMin(argv[3]);
	p1 = PPMcvt(p1, ee, nthu);	// convert PPM
	PPMout(p1, argv[4]);		// output p1 to new
	return 0;
}

IMG *PPMin(char *inFile)		// function to read PPM 
{
	int i, j;			// variables for counting
	IMG *pic;			// IMG pointer to store inFile
	FILE *fin;			// readed file
	
	pic = (IMG *)malloc(sizeof(IMG));	// give pic a space
	fin = fopen(inFile, "r");			// open file for reading
	fscanf(fin, "%s", pic->header);		// read it's header
	fscanf(fin, "%d %d\n%d\n", &pic->W, &pic->H, &pic->level);	// H, W, level
	pic->PX = (PIXEL **)malloc(pic->W*sizeof(PIXEL *));	// give PIXEL spaces
	for (i=0; i<pic->W; i++){
		pic->PX[i] = (PIXEL *)malloc(pic->H*sizeof(PIXEL));
	}
	for (j=0; j<pic->H; j++){
		for (i=0; i<pic->W; i++){			// get PIXEL from column-major to 
			pic->PX[i][j].r = getc(fin);	// row-major
			pic->PX[i][j].g = getc(fin);
			pic->PX[i][j].b = getc(fin);
		}
	}
	fclose(fin);				// close file
	return pic;
}

void *PPMout(IMG *p1, char *outFile)	// function to output file
{
	int i, j;			// variables for counting
	FILE *fout;			// file to output
	
	fout = fopen(outFile, "w");		// open file to write
	fprintf(fout, "%c%c\n", p1->header[0], p1->header[1]);	// put header
	fprintf(fout, "%d %d\n%d\n", p1->W, p1->H, p1->level);	// put H W level
	for (j=0; j<p1->H; j++){
		for (i=0; i<p1->W; i++){
			fprintf(fout, "%c", p1->PX[i][j].r);	// output each PIXELs
			fprintf(fout, "%c", p1->PX[i][j].g);
			fprintf(fout, "%c", p1->PX[i][j].b);
		}
	}
	fclose(fout);			// close file
}

IMG *PPMcvt(IMG *p1, IMG *ee, IMG *nthu)	// function to convert
{
	int i, j, a, b, Hnew, Wnew, sqH, sqW;

	for (j=0; j<p1->H; j++){			// convert p1 into gray scale
		for (i=0; i<p1->W; i++){
			p1->PX[i][j].r *= 0.2126;
			p1->PX[i][j].r += p1->PX[i][j].g*0.7152;
			p1->PX[i][j].r += p1->PX[i][j].b*0.0722;
			p1->PX[i][j].g = p1->PX[i][j].r;
			p1->PX[i][j].b = p1->PX[i][j].r;
		}
	}

	Hnew = (p1->H) - (ee->H);			// find where to start printing EE
	Wnew = (p1->W) - (ee->W);
	for (j=Hnew, b=0; j<p1->H; j++, b++){
		for (i=Wnew, a=0; i<p1->W; i++, a++){
			if((ee->PX[a][b].r==255)&&(ee->PX[a][b].g==255)&&
			   (ee->PX[a][b].b==255)){		// if white then do nothing
			}else{
				p1->PX[i][j].r = ee->PX[a][b].r;	// else print EE
				p1->PX[i][j].g = ee->PX[a][b].g;
				p1->PX[i][j].b = ee->PX[a][b].b;
			}
		}
	}

	Hnew = (p1->H)/2-(nthu->H)/2;		// find where to start printing nthu
	Wnew = (p1->W)/2-(nthu->W)/2;
	for (j=Hnew, b=0; j<(Hnew+(nthu->H)); j++, b++){
		for (i=Wnew, a=0; i<(Wnew+(nthu->W)); i++, a++){
			if((nthu->PX[a][b].r==255)&&(nthu->PX[a][b].g==255)&&
			   (nthu->PX[a][b].b==255)){	// if white then do nothing
			}else{
				p1->PX[i][j].r = 255;		// else turn purple
				p1->PX[i][j].b = 255;
			}
		}
	}

	sqH=880;			// find the light bulbs at the right 
	sqW=5170;
	for(j=sqH; j<sqH+10; j++){			// draw the upper side of the block
		for(i=sqW; i<sqW+280; i++){
			p1->PX[i][j].r = 255;
			p1->PX[i][j].g = 255;
			p1->PX[i][j].b = 255;
		}
	}
	for(j=sqH; j<sqH+220; j++){			// draw the left side of the block
		for(i=sqW; i<sqW+10; i++){
			p1->PX[i][j].r = 255;
			p1->PX[i][j].g = 255;
			p1->PX[i][j].b = 255;
		}
	}
	sqW += 270;							// draw the right side of the block
	for(j=sqH; j<sqH+220; j++){
		for(i=sqW; i<sqW+10; i++){
			p1->PX[i][j].r = 255;
			p1->PX[i][j].g = 255;
			p1->PX[i][j].b = 255;
		}
	}
	sqH += 210;
	sqW -= 270;
	for(j=sqH; j<sqH+10; j++){			// draw the lower side of the block
		for(i=sqW; i<sqW+280; i++){
			p1->PX[i][j].r = 255;
			p1->PX[i][j].g = 255;
			p1->PX[i][j].b = 255;
		}
	}
	return p1;				// return p1
}
