#include <stdio.h> 
int main() { 
    int exercise;
    int power = 0;

    printf("Choose exercise(1, 2 or 3): ");
    scanf("%d", &exercise);

    if(exercise == 1){
        int arrU[10] = { 1,2,3,4,5,6,7,8,9,10 }; // універсальна множина 
        int arrA[10] = { 1,1,1,1,1,1,1,0,0,0 }; // множина A 
        int arrB[10] = { 0,0,0,1,1,1,1,1,1,1 }; // множина B 
        int arrC[10] = { 1,0,1,0,1,0,1,0,1,0 }; // множина C 
        int arrD[10] = { 0 };  // шукана множина D 
        
        printf("D = ( "); 
            for (int i = 0; i < 10; i++) { 
                arrD[i] = (arrA[i]||arrC[i])&&!arrB[i]; 
                printf("%d ", arrD[i]); 
        } 
        printf(")"); 
        printf("\n"); 
        printf("D = { "); 
        for (int i = 0; i < 10; i++) { 
            if (arrD[i] == 1) {
                printf("%d ", arrU[i]); 
                power++;
            }
        } 
        printf("}\n"); 
    }

    
    printf("Power: %d\n", power);

    return 0;  
} 