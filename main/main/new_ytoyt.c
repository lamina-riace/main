/* new_ytoyt.c */

/****************************/
/*   ]usñğvZµÜ·B	*/
/****************************/

#include<stdio.h>
// yt -> yyÌ]usñiÎpüÅüÎÌj
void new_ytoyt(double **yy, double **yt, int data){
	int i, j;

	for(i = 0; i < 64; i++)
		for(j = 0; j < data; j++)
			yt[j][i] = yy[i][j];

}