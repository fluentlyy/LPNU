#include <stdio.h>

#define SIZE 4

int main(){
    int matrix[SIZE][SIZE] = {
        { 12, -45,   7, -23},
        {-89,  34, -16,  90},
        { 67, -11, -52,  78},
        {-15,  88,  43, -61}
    };
    int count = 0;
    for(int i = 3;i > 0; i--){
        for(int j = i - 1;j >= 0; j--){
            if(matrix[i][j] > 0){
                count++;
            }
        }
    }
    printf("%d", count);

    return 0;
}

