#include <stdio.h>
#include "my_mat.h"

int main()
{
	int mat[10][10]; // initialization
	char c, ch1; // c the input from the user, ch1 for \n chars we will get in adition
	scanf("%c", &c);
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
		scanf("%c%c",&ch1, &c);

	}
	return 0;
}
