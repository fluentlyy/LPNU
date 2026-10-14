#include <stdio.h>
#define SIZE 10

int main(void){
    double vect[SIZE];
    int maxIndx = 0;
    int minIndx = 0;
    int startIndx, endIndx;
    double sum, average, count;

    for(int i = 0; i < SIZE; i++){
        printf("Enter a value: ");
        scanf("%lf", vect + i);

        if(*(vect + maxIndx) < *(vect + i)){
            maxIndx = i;
        }
        if(*(vect + minIndx) > *(vect + i)){
            minIndx = i;
        }
    }
    if(maxIndx > minIndx){
        startIndx = minIndx + 1;
        endIndx = maxIndx;
    }else{
        startIndx = maxIndx + 1;
        endIndx = minIndx;
    }
    
    for(startIndx;startIndx < endIndx; startIndx++){
        sum += vect[startIndx];
        count++;
    }
    average = sum / count;
    printf("%lf", average);

    return 0;
}