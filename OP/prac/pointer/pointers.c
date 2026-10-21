#include <stdio.h>
#include <math.h>
#define SIZE 15

int main(){
    int array[SIZE] = {1, 12, 5, 0, 9, 101, 45, 66, 3, 4, 7, 70, 44, 1488, 67};
    int sum = 0, count = 0, sumLessAverage = 0, approxToAverage = 0;
    double average = 0;
    for(int i = 0; i < SIZE; i ++){
        sum += *(array + i);
    }
    average = sum / (double)SIZE;
    approxToAverage = *array;

    for(int i = 0; i < SIZE; i ++){
        if(*(array + i) > average){
            count++;
        }else{
            sumLessAverage += *(array + i);
        }
        

    }

    printf("%lf\n", average);
    printf("%d\n", count);
    printf("%d\n", sumLessAverage);
    printf("%lf", approxToAverage);


    return 0;
}