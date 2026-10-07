#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    int min = matrix[0][0];
    int max = matrix[0][0];
    int * ptr = NULL;
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
            if(i == j){
                if(min > matrix[i][j]){
                    min = matrix[i][j];
                }
            }
            if(i + j ==  3){
                if(max < matrix[i][j]){
                    max = matrix[i][j];
                }
            }
            if(matrix[i][j] == min){
                ptr = *(matrix + i) + j;
            }
            if(matrix[i][j] == max){
                matrix[i][j] = min;
                *ptr = max;
            }
            
            printf("%d ", matrix[i][j]);
        }
    }
    
    return 0;
}