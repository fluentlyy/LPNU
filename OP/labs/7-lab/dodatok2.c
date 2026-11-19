#include <stdio.h>
#include <math.h>

#define F(x) ((x) * (x) * cos(x))
#define PI 3.141592653589793


void tab_for(double h);
void tab_while(double h);
void tab_dowhile(double h);

int main(){
    void (*tab_ptr)(double);
    int mode;
    double step;

    printf("Enter a mode(1 - for, 2 - while, 3 - do while): ");
    scanf("%d", &mode);

    if(mode == 1){
        tab_ptr = tab_for;
    }else if (mode == 2){
        tab_ptr = tab_while;
    }else if (mode == 3){
        tab_ptr = tab_dowhile;
    }else{
        printf("Error");
        return 0;
    }

    printf("Enter a step: ");
    scanf("%lf", &step);

    tab_ptr(step);
    return 0;
}

void tab_for(double h){
    for(double x = 0; x <= 2 * PI; x = x + h){
        printf("x = %.4lf \t f(x) = %.4lf\n", x, F(x));
    }
}

void tab_while(double h){
    double x = 0;
    while(x <= 2 * PI){
        printf("x = %.4lf \t f(x) = %.4lf\n", x, F(x));
        x = x + h;
    }
}
void tab_dowhile(double h){
    double x = 0;
    do{
        printf("x = %.4lf \t f(x) = %.4lf\n", x, F(x));
        x = x + h;
    }while(x <= 2 * PI);
}