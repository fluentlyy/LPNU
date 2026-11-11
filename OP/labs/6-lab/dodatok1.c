#include <stdio.h>

int main(){
    void replaceCols(int rows, int cols, int matrix[rows][cols], int colIndx1, int colIndx2);

    int matrix[4][3] = {
        {  15,   -3,  42 },
        {   0,   88, -19 },
        {   7,  104,  31 },
        { -52,    6,  14 }
    };

    replaceCols(4, 3, matrix, 0, 2);
    replaceCols(4, 3, matrix, 1, 2);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void replaceCols(int rows, int cols, int matrix[rows][cols], int colIndx1, int colIndx2){
    for(int i = 0; i < rows; i++){
        int temp = matrix[i][colIndx2];
        matrix[i][colIndx2] = matrix[i][colIndx1];
        matrix[i][colIndx1] = temp;
    }
}
