#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Enter a value for N");
        return 0;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be positive");
        return 0;
    }

    double arr[N];
    for(int i = 0; i < N; i++){
        printf("Enter %d element: ", i + 1);
        scanf("%lf", &arr[i]);
    }

    double max_val;
    int max_indx;

    maxValArray(arr, N, &max_val, &max_indx);
    printf("Maximum value: %lf, position: %d\n", max_val, max_indx);

    return 0;
}