#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    
    for(int i = 0;i < 4; i++){
        int rowSum = 0;
        for(int j = 0;j < 4; j++){
              rowSum += matrix[i][j];
        }
        if(i > 0){
            
        }
    }
   
    printf("%d", sum1);
   
    return 0;
}