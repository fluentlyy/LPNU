#include <stdio.h>

void to_octal(int num){
    if(num == 0) return;
    to_octal(num / 8);
    printf("%d", num % 8);
}

int is_simple(int num){
    if(num < 2) return 0;
    
    for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
        return 0;
    }
}
}

int main(){

    for(int i = 0; i <= 100; i++){
        if(is_simple(i)){
            printf("%d - ", i);
            to_octal(i);
            printf("\n");
        }
    }
    return 0;
}