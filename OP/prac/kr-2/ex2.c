#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    int max = matrix[0][0];
    for(int i = 3;i > 0; i--){
        for(int j = i - 1;j >= 0; j--){
            if(max < matrix[i][j]){
                max = matrix[i][j];
            }
            printf("%d\n", matrix[i][j]);
        }
    }
    printf("Max: %d", max);

    return 0;
}

