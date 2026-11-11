#include <stdio.h>

#include "functions.h"
int main(){
    double a = 0.0;
    double b = 2.0;
    double h;
    printf("Введіть h \n");
    if(scanf("%lf",&h)!= 1 || h <= 0){
        printf("h повинно бути додатнім \n");
        return 1;
    }

    printf("Табулювання x /sqrt(3*x +2) \n");
    printf("Інтервал : [%f,%f] h = %f\n",a,b,h);
    tabulate(a,b,h);
    return 0;
}