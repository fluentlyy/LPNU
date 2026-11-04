#include <stdio.h>
#include <math.h>

double calc_y1(double x);
int calc_y2(double x, double *py);

void tabulation1(double h){
    double pi = M_PI;
    printf("%-12s | %-12s\n", "X", "Y");
    printf("-----------------------\n");

    for(double x = 0; x <= 100 * pi; x = x + h){
        double y = calc_y1(x);
        printf("%-12lf | %-12lf\n", x, y);
    }

    printf("-----------------------\n");
}

void tabulation2(double h){
    double pi = M_PI;
    double y_val;
    printf("%-12s | %-12s | %-4s\n", "X", "Y", "Sign");
    printf("----------------------------------\n");

    for(double x = 0; x <= 100 * pi; x = x + h){
        int y_sign = calc_y2(x, &y_val);
        printf("%-12lf | %-12lf | %-12d\n", x, y_val, y_sign);
    }
    printf("----------------------------------\n");
}