#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    for(int i = 0;i < 3; i++){
        for(int j = 0;j < 3 - i; j++){
               matrix[i][j] = 0;
        }
    }
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
               printf("%d ", matrix[i][j]);
               if(j == 3){
                printf("%d\n", matrix[i][j]);
               }
        }
    }

    
   
    return 0;
}