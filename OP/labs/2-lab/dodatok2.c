#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, res, step;
    double eps = 0.0001;

    printf("ODZ: [-1;+inf)\n");
    
    printf("Enter A: ");
    scanf("%lf", &a);
    if(fabs(a) > 1){
        printf("Error");
        return 0;
    }

    printf("Enter B: ");
    scanf("%lf", &b);
    if((fabs(b) > 1) || (b <= a)){
        printf("Error");
        return 0;
    }

    printf("Enter step: ");
    scanf("%lf", &step);

    while(a <= b){
        res = pow((1 + a), 0.25);
        printf("---------------------------\n");
        printf("%lf\n", res);


        double term = 1.0;
        double sum = 1.0;
        int n = 1;
        while(fabs(term) >= eps){

            term = term * (-1.0 * ((4.0 * n - 5.0)/ (4.0*n)) * a);
            sum += term;

            n++;
        }
        printf("%lf\n", sum);
        printf("---------------------------\n");

        a += step;
    }

    return 0;
}