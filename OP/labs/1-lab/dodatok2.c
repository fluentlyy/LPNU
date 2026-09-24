#include <stdio.h>
#include <math.h>

int main(void){
    int num;
    printf("Enter a six-digit number:\n");
    scanf("%d", &num);
    if(num >= 100000 && num <= 999999){
        int rest, res, i, cache, state;
        i = 0;
        res = 0;
        state = 0;
        start:
            rest = num % 10;
            if(rest < 5){
                num = num / 10;
                cache = rest * pow(5,i);
                res = res + cache;
                i++;
                if(num != 0){        
                    goto start;
                }   
            }else{
                state = 1;
            }
        if(state){
            printf("Invalid number: not 5 base\n");
        }else{
            printf("Your num is: %d\n", res);   
        }
        
    }else{
        printf("Invalid number: not six digit\n");
    }
    return 0;
}