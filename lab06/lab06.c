/* EE2310 Lab06. Finding Sudoku Solutions
   106061146, Chen Jhao-Ting
   2017,10,31
*/

#include <stdio.h>

int num = 0;				// number of solutions
int mat[9][9] = {0};		// matrix for solution
int resumemat[9][9] = {0};	// matrix for resume

int readdat(void);		// read data to 2 arrays
int printdat(void);				// print solution
int iscorrect(int row, int col, int testnum); // check testnum
int fillin(int row, int col, int result, int i);	// put in number
int resume(int row, int col);	// resume

int main(void)
{
	int result = 0;		// first result = 0
	
	readdat();		// read data from the folder
	fillin(0,0,result,1);		// find the solutions
	printf("Total number of solutions found: %d.\n", num);	// num of solutions
	
	return 0;
}

int readdat(void)		// read data to 2 arrays
{
	int i,j;										// reading
	for (i=0 ; i<9 ; i++){
		for ( j=0 ; j<9 ; j++){
			scanf(" %c", &mat[i][j]);
			resumemat[i][j] = mat[i][j];			// 1 dat for solution
			if ( mat[i][j] == '.' ){	// 1 dat for resume find more solution
				mat[i][j] = 0;				// if '.' change to 0
				resumemat[i][j] = 0;
			}
			else{
				mat[i][j] -= '0';			// from ASCII to int
				resumemat[i][j] -= '0';
			}
		}
	}
}

int printdat(void)				// print solution
{	
	int i,j;
	num++;								// num++
	printf("Solution %d:\n",num);
	for ( i=0 ; i<9 ; i++ ){
		printf(" ");
		for ( j=0 ; j<9 ; j++ ){
			printf(" %d", mat[i][j]);
			if( (j+1)%3 == 0 && j != 0 && j != 8 ){
				printf(" |");			// line between 3 collums
			}
		}
		printf("\n");
		if( (i+1)%3 == 0 && i != 0 && i != 8 ){	// the line between 3 rolls
			printf("  ------|-------|------\n");
		}
	}
}

int iscorrect(int row, int col, int testnum) // check testnum
{
	int i;												// is correct or not
	int rowsquare = (row/3)*3, colsquare = (col/3)*3;	// square check	
	for (i = 0; i<9; i++){
		if( mat[row][i] == testnum ) return 0;			// col check
		if( mat[i][col] == testnum ) return 0;			// roll check
		if( mat[rowsquare + (i%3)][colsquare + (i/3)] == testnum ) return 0;
	}													// square check
	return 1;									// 1 == all right
}

int fillin(int row, int col, int result, int i)
{
	if( row < 9 && col < 9 ){		// 'fill in number' func if not yet finish
		if( mat[row][col] != 0 ){				// if num is part of the ques
			if( (col+1)<9 ){						// if did not > 9 col
				return fillin(row, col+1, result, 1);	// check nextnum
			}
			else if( (row+1)<9 ){					// if col>9
				return fillin(row+1, 0, result, 1);	// next roll
			}
			else{								// if all found
				result++;						// result ++(!=0)		
				printdat();					// print solution
				return result;					// result != 0
			}
			resume(row, col-1);	// back to last step for more ans
		}
		else{						// if == 0
			for ( i ; i<=9 ; i++ ){		// put in number 1 to 9
				if ( iscorrect(row, col, i) == 1 ){	// if num correct
					mat[row][col] = i;				// put in the right num
					if( (col+1)<9 ){					// if col<9
						if( fillin(row, col+1, result, 1) == 1 ){
							return result;		// next num try(result =0)
						}
						else{						// if the num is wrong
							mat[row][col] = 0;	// restart number till right
						}
					}
					else if( (row+1)<9 ){				// if col>9
						if( fillin(row+1, 0, result, 1) == 1 ){
							return result;		// next roll try(result = 0)
						}
						else{						// if the num is wrong
							mat[row][col] = 0;	// restart the num till right
						}
					}
					else{							// if all num are put in
						result++;				// result++(!=0)
						printdat();			// print solution
						return result;			// result != 0
					}
				}
				resume(row, col);		// resume for next ans
			}
		}
		return result;					// if no ans then return 0
	}
	else{
		return result;				// if all find then return result
	}
}

int resume(int row, int col)	// resume
{
	int k;				// resume mat from assigned position to end
	int j;									
	for ( j = row ; j<9 ; j++ ){
		for( k = col ; k<9 ; k++ ){
			mat[j][k] = resumemat[j][k];
		}
		col = 0;
	}
}
