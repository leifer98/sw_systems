#include <stdio.h>

int d(int mat[10][10], int x, int y) {
    int dat[10][10];
    int sum, i, j, k;

    for (i = 0 ; i < 10 ; i++) {
        for (j = 0 ; j < 10 ; j++) {
            if (i == j) {
                dat[i][j] = 0;
            } else if (mat[i][j] > 0) {
                dat[i][j] = (1 + mat[i][j]) - 1;
            } else {
                dat[i][j] = 100;                
            }
        }
    }
    
    for (k = 0 ; k < 10 ; k++) {
        // printf("\n k=%d, \n", k);
        // for (int i = 0 ; i < 10 ; i++) {
        //     for (int j = 0 ; j < 10 ; j++) {
        //         printf("%d ,\t", dat[i][j]);
        //     }
        //     printf("\n");
        // }
        for (i = 0 ; i < 10 ; i++) {
            for (j = 0 ; j < 10 ; j++) {
                    sum = ((dat[i][k]) + (dat[k][j]));
                    if (sum < dat[i][j]) {
                        dat[i][j] = sum;
                        dat[j][i] = sum;
                    }
                    if (dat[i][j] > 100){
                        dat[i][j] = 100;
                        dat[j][i] = 100;
                    }
            }
        }
    }
    return dat[x][y]; //need to add array for dynamic algo to restore previous results.
}

void b_function(int mat[10][10], int i, int j) {
    int result = d(mat,i,j);
    if (result < 100) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void c_function(int mat[10][10], int x, int y) {
    int result = d(mat,x,y);
    if (result < 100) {
        printf("%d", result);
        return;
    } else{
        printf("-1");        
    }
}

void a_function( int mat[10][10] ) {
	for (int i = 0 ; i < 10 ; i++) {
		for (int j = 0 ; j < 10 ; j++) {
			int num;
					scanf("%d\n", &num);

					mat[i][j] = num;
		}		
	}
}
