#include <stdio.h>
#define SIZE 4

int main(){
    double matrix[SIZE][SIZE];
    double tempArr[SIZE];

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("Enter a value: ");
            scanf("%lf", *(matrix + i) + j);
            if(i == SIZE - 1){
                *(tempArr + j) = (*(matrix + i))[j];
            }
        }
    }
    printf("-----------------------------------------\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){  
                if(j == SIZE - 1){
                    printf("%f\n", *(*(matrix + i) + j));
                }else{
                    printf("%f ", *(*(matrix + i) + j));
                }
        }
    }
    printf("-----------------------------------------\n");
    for(int i = SIZE - 1; i >= 0; i--){
        for(int j = 0; j < SIZE; j++){
            if(i == 0){
               *(*(matrix + i) + j) = *(tempArr + j);
            }else{
                *(*(matrix + i) + j) = *(*(matrix + (i - 1)) + j);
            }
            
        }
    }
    printf("-----------------------------------------\n");
     for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){  
                if(j == SIZE - 1){
                    printf("%f\n", *(*(matrix + i) + j));
                }else{
                    printf("%f ", *(*(matrix + i) + j));
                }
        }
    }
    printf("-----------------------------------------\n");
    return 0;
}


