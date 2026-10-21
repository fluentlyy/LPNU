#include <stdio.h>

int main(){
    int R1[3][3];
    int R2[3][3] = {
        {0 , 0, 1},
        {1, 0, 0},
        {0, 0, 0}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0;j < 3;j++){
            while(1){
            printf("M[%d][%d] = ", i + 1, j + 1);
            int scanRes = scanf("%d", *(R1 + i) + j);
            if(scanRes != 1){
                printf("Error, you must enter 0 or 1.");
                while(getchar() != '\n');
            }else if(R1[i][j] != 1 && R1[i][j] != 0){
                printf("Error, you must enter 0 or 1.");
            }else{
                break;
            }
            }
        }
    }

    printf("------\n");
    
    for(int n = 0; n < 8; n++){
        int matrix[3][3] = {0};
        if (n == 0) printf("R1:\n");
        else if (n == 1) printf("R1^-1:\n");
        else if (n == 2) printf("R1 INTERSECTION R2:\n");
        else if (n == 3) printf("R1 UNION R2:\n");
        else if (n == 4) printf("R1 \\ R2:\n");
        else if (n == 5) printf("R1 SYMMETRIC DIFF R2:\n");
        else if (n == 6) printf("NOT R1:\n");
        else if (n == 7) printf("R2 o R1:\n");
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(n == 0){
                    matrix[i][j] = R1[i][j];
                    printf("%d ", matrix[i][j]);
                }else if(n == 1){
                    matrix[i][j] = R1[j][i];
                    printf("%d ", matrix[i][j]);
                }else if(n == 2){
                    matrix[i][j] = R1[i][j] && R2[i][j];
                    printf("%d ", matrix[i][j]);
                }else if(n == 3){
                    matrix[i][j] = R1[i][j] || R2[i][j];
                    printf("%d ", matrix[i][j]);
                }else if(n == 4){
                    matrix[i][j] = R1[i][j];
                    if(R1[i][j] && R2[i][j]){
                        matrix[i][j] = 0;
                    }
                    printf("%d ", matrix[i][j]);
                }else if(n == 5){
                    if(R1[i][j] != R2[i][j]){
                        matrix[i][j] = 1;
                    }else{
                        matrix[i][j] = 0;
                    }
                    printf("%d ", matrix[i][j]);
                }else if(n == 6){
                    matrix[i][j] = !R1[i][j];
                    printf("%d ", matrix[i][j]);
                }else if(n == 7){
                    for (int k = 0; k < 3; k++) {
                        if (R1[i][k] && R2[k][j]) {
                            matrix[i][j] = 1;
                            break;
                        }
                    }
                    printf("%d ", matrix[i][j]);
                }
                
            }
            printf("\n");
        }
        printf("------\n");
    }


    return 0;
}