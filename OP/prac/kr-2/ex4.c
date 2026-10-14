#include <stdio.h>

int main(){
    int matrix[4][4] = {
        {12, 45,  7, 23},
        {89, 34, 16, 90},
        {67, 11, 52, 78},
        {15, 88, 43, 61}
    };
    double sum = 0, average;
    int count = 0;
    for(int i = 0;i < 3; i++){
        for(int j = 0;j < 3 - i; j++){
                count++;
                sum += matrix[i][j];
        }
    }

    average = sum / count;
    printf("%lf", average);
    return 0;
}