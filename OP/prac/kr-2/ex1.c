#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    int min = matrix[0][0];
    for(int i = 0;i < 4; i++){
        for(int j = i + 1;j < 4; j++){
            if(min > matrix[i][j]){
                min = matrix[i][j];
            }
            printf("%d\n", matrix[i][j]);
        }
    }
    printf("Min: %d", min);

    return 0;
}

