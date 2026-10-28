#include <stdio.h>
#define SIZE 5

int main(){
    int matrix[SIZE][SIZE];
    int isReflective = 0;
    int isSymmetrical = 0;
    int isTrans = 1;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0;j < SIZE;j++){
            while(1){
            printf("M[%d][%d] = ", i + 1, j + 1);
            int scanRes = scanf("%d", *(matrix + i) + j);
            if(scanRes != 1){-
                printf("Error, you must enter 0 or 1.");
                while(getchar() != '\n');
            }else if(matrix[i][j] != 1 && matrix[i][j] != 0){
                printf("Error, you must enter 0 or 1.");
            }else{
                break;
            }
            }
        }
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0;j < SIZE;j++){
            printf("%d ", matrix[i][j]);
            if(matrix[i][j] == matrix[j][i]){
                if(i == j){
                    if(matrix[i][j]){
                        isReflective++;
                    }
                    continue;
                }
                isSymmetrical++;
            }
            for(int k = 0; k < SIZE;k++){
                if(matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] == 0){
                    isTrans = 0;
                }
            }
        }
        printf("\n");
    }
    if(isReflective == SIZE){
        printf("Matrix is reflective\n");
        isReflective = 1;
    }else{
        printf("Matrix isn`t reflective\n");
        isReflective = 0;
    }
    if(isSymmetrical == (SIZE * SIZE) - SIZE){
        printf("Matrix is symmetrical\n");
        isSymmetrical = 1;
    }else{
        printf("Matrix isn`t symmetrical\n");
        isSymmetrical = 0;
    }
    if(isTrans){
        printf("Matrix is transitive\n");
    }else{
        printf("Matrix isn`t transitive\n");
    }
    printf("Result: ");
    if(isReflective && isSymmetrical && isTrans){
        printf("Equal");
    }else if(isReflective && isSymmetrical && !isTrans){
        printf("Tolerance");
    }else if(isReflective && !isSymmetrical && isTrans){
        printf("Not strict");
    }else if(!isReflective && !isSymmetrical && isTrans){
        printf("Strict");
    }else{
        printf("Random");
    }
    return 0;
}