#include <stdio.h>
#include "functions.h"

int main(){

    double h;

    printf("Enter step: ");
    scanf("%lf", &h);

    printf("\n===== TABULATION 1 =====\n");
    tabulation1(h);

    printf("\n========== TABULATION 2 ==========\n");
    tabulation2(h);

    return 0;
}