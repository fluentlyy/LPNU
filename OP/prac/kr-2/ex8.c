#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    int rowSum = 0;
    int rowCompare;
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
              rowSum += matrix[i][j];
        }
        rowCompare = rowSum;
        if(rowCompare)
    }
   
    printf("%d", sum1);
   
    return 0;
}