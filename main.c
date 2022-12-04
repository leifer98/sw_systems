#include <stdio.h>
#include "my_mat.h"

int main()
{
	int mat[10][10];

	// int mat[10][10] = {	{0,3,1,0,0,2,0,0,0,0},
	// 					{3,0,1,0,0,0,0,0,0,0},
	// 					{1,1,0,0,0,0,0,0,0,0},
	// 					{0,0,0,0,0,0,0,5,0,0},
	// 					{0,0,0,0,0,0,0,4,1,1},
	// 					{2,0,0,0,0,0,2,0,0,0},
	// 					{0,0,0,0,0,2,0,0,0,0},
	// 					{0,0,0,5,4,0,0,0,0,2},
	// 					{0,0,0,0,1,0,0,0,0,0},						
	// 					{0,0,0,0,1,0,0,2,0,0}};

	char c;
	scanf("%s", &c);
	int i, j;
	while (c != 'D') {
		if (c == 'A') {
			a_function(mat);
		} else if (c == 'B') {
			scanf("%d", &i);
			scanf("%d", &j);
			b_function(mat,i,j);
		} else if (c == 'C') {
			scanf("%d", &i);
			scanf("%d", &j);
			c_function(mat,i,j);
		} else {
			printf("\nnot correct input");
		}
		scanf("%s", &c);

	}
	return 0;
}
