#include <stdio.h> 
int main() { 
    int pInput, qInput, rInput, resInput;

    printf("Enter P(0 or 1):");
    scanf("%d", &pInput);

    printf("Enter Q(0 or 1):");
    scanf("%d", &qInput);

    printf("Enter R(0 or 1):");
    scanf("%d", &rInput);

    if((pInput == 0 || pInput == 1) && (qInput == 1 || qInput == 0) && (rInput == 1 || rInput == 0)){
        resInput = (pInput && qInput) || (!pInput && !qInput) || rInput;
        printf("Result: %d\n",resInput);
       
        printf("_________________________________________________________________\n"); 
        printf("|\t P\t |\t Q\t |\t R\t |\tResult\t|\n");  
        printf("_________________________________________________________________\n"); 
      
        for (int p = 0; p <= 1; p++) { 
            for (int q = 0; q <= 1; q++) { 
                for (int r = 0; r <= 1; r++) { 
                   
                    int res = (p && q) || (!p && !q) || r;  
                   
                    printf("|\t %d\t |\t %d\t |\t %d\t |\t %d\t|\n", p, q, r, res); 
                } 
            } 
        } 
        printf("_________________________________________________________________\n"); 
    }else{
        printf("Incorrect values\n");
    }

    return 0;  
} 
