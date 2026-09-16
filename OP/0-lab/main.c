#include <stdio.h>

int main(void){
    int a;
    int z, s;
    a = 567;
    s = 0;
    start:
        z = a % 10;//отримуємо залишок
        s = s + z; //добавляємо залишок
        printf("%d\n", s);
        a = a/10;
        if(a != 0){
            goto start;
        }
    
    return 0;
}
