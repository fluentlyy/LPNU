#include <stdio.h>
#include <math.h>

int main(void){
    int r, count;

    count = 0;

    printf("Enter R: ");
    scanf("%d", &r);

    for(int x = -r; x <= r; x++){
       for(int y = -r; y <= r; y++){
        
        if(pow(x, 2) + pow(y, 2) <= pow(r, 2)){
            count++;
        }

        } 
    }
    printf("%d", count);
    
    return 0;
}