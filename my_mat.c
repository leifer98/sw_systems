#include <stdio.h>

int d(int mat[10][10], int x, int y) {
    int dat[10][10]; // d function acording to the algorithm
    int sum, i, j, k;
    // initializing k = 0 for the algorithm
    for (i = 0 ; i < 10 ; i++) {
        for (j = 0 ; j < 10 ; j++) {
            if (i == j) {
                dat[i][j] = 0;
            } else if (mat[i][j] > 0) {
                dat[i][j] = (1 + mat[i][j]) - 1;
            } else {
                dat[i][j] = __INT_MAX__; // max value               
            }
        }
    }
    // the algorithm itself
    for (k = 0 ; k < 10 ; k++) {
        for (i = 0 ; i < 10 ; i++) {
            for (j = 0 ; j < 10 ; j++) {
                    if (__INT_MAX__ !=  dat[i][k] && __INT_MAX__ !=  dat[k][j]) {
                        sum = ((dat[i][k]) + (dat[k][j]));
                        if (sum < dat[i][j]) {
                            dat[i][j] = sum;
                            dat[j][i] = sum;
                        }
                    }
                    
            }
        }
    }
    return dat[x][y];
}

void b_function(int mat[10][10], int i, int j) {
    int result = d(mat,i,j); // uses the c function and conclude the result for the b function
    if (result < 100 && result > 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void c_function(int mat[10][10], int x, int y) {
    int result = d(mat,x,y);
    if (result < 100 && result > 0) {
        printf("%d\n", result);
        return;
    } else{
        printf("-1\n");        
    }
}

void a_function( int mat[10][10] ) {
    int num;
	for (int i = 0 ; i < 10 ; i++) {
		for (int j = 0 ; j < 10 ; j++) {
            scanf("%d", &num);
            mat[i][j] = num;
		}		
	}
}