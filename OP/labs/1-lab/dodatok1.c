#include <stdio.h>
#include <math.h>

int main(void){
    /* Змінні */
    double b, x, z;
    /* Введення х */
    printf("Enter x:\n");
    scanf("%lf", &x);
    /* Введення z */
    printf("Enter z:\n");
    scanf("%lf", &z);
    /* Розрахунок */
    b = sqrt(exp(x - (1/sin(z))));
    printf("%f\n", b);
    
    return 0;
}