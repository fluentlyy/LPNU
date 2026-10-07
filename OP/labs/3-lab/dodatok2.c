#include <stdio.h>
#include <math.h>

int main(){
    double matrix[5][5] = {
        {12, -5, 8, -3, 1},
        {-25, 14, 0, -18, 6},
        {4, -10, 2, -1, 15},
        {-9, 7, -20, 11, -4},
        {3, -16, 13, 22, -2}
    };
    double max = fabs(matrix[0][0]);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(max < fabs(matrix[i][j])){
                max = fabs(matrix[i][j]);
            }
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
             matrix[i][j] /= max;
             printf("%lf\n", matrix[i][j]);
        }
    }

    return 0;
}