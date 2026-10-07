#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    int sum = 0;
    for(int i = 0;i < 4; i++){
        for(int j = 3;j >= 0; j--){
            if(i + j == 3){
                sum += matrix[i][j];
            }
        }
    }
    printf("Sum: %d", sum);

    return 0;
}

