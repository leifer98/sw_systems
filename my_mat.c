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
                    if (i == 6 && j == 7 && k==5) {
                        printf("%d,%d,%d \n", dat[k][j], (dat[i][k]), dat[i][j]);
                    }
                    sum = ((dat[k][j]) + (dat[i][k]) );
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
        return;
    }
    printf("False\n");
    return;
}

int c_function(int mat[10][10], int x, int y) {
    int result = d(mat,x,y);
    if (result < 100) {
        return result;
    }
    return -1;
}
