#include <stdio.h>

int main(){
    int matrix[4][4];
    int isReflective = 0;
    int isSymmetrical = 0;
    int isTrans = 1;
    for(int i = 0; i < 4; i++){
        for(int j = 0;j < 4;j++){
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
    for(int i = 0; i < 4; i++){
        for(int j = 0;j < 4;j++){
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
            for(int k = 0; k < 4;k++){
                if(matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] == 0){
                    isTrans = 0;
                }
            }
        }
        printf("\n");
    }
    if(isReflective == 4){
        printf("Matrix is reflective\n");
        isReflective = 1;
    }else{
        printf("Matrix isn`t reflective\n");
        isReflective = 0;
    }
    if(isSymmetrical == 12){
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