#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, res, step;
    double eps = 0.0001;
    
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


    printf("\n+------------+------------+------------+\n");
    printf("|     x      |  default   |   taylor   |\n");
    printf("+------------+------------+------------+\n");

    while(a <= b){
        res = pow((1 + a), 0.25);


        double term = 1.0;
        double sum = 1.0;
        int n = 1;
        while(fabs(term) >= eps){

            term = term * (-1.0 * ((4.0 * n - 5.0)/ (4.0*n)) * a);
            sum += term;

            n++;
        }
       printf("| %10.4lf | %10.6lf | %10.6lf |\n", a, res, sum);

        a += step;
    }

    printf("+------------+------------+------------+\n");

    return 0;
}