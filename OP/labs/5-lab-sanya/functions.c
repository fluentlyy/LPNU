#include <stdio.h>
#include <math.h>
#include "functions.h"
double calc_way1(double x){
    return x / sqrt(3 * x +2.0);
}
int calc_way2(double x,double *y){
    *y =  x / sqrt(3 * x +2.0);
    if(*y < 0.0){
        return -1;
    }
    else  if(*y == 0){
        return 0;
    }
    else {
        return 1;
    }
}
void tabulate(double a, double b,double h)
{
    printf("+--------+------------+------------+--------------+\n");
    printf("|   x    |  Way 1 (y) |  Way 2 (y) | Sign (Way 2) |\n");
    printf("+--------+------------+------------+--------------+\n");

    for(double x = a;x<=b+ h /2.0;x+=h){
        double y1 = calc_way1(x);
        double y2 = 0.0;
        int sign = calc_way2(x,&y2);
        printf("| %6.2f | %10.4f | %10.4f | %12d |\n", x, y1, y2, sign);
    }
        printf("+--------+------------+------------+--------------+\n");
    }