#include "array_utils.h"

void maxValArray(double arr[], int size, double *maxVal, int *maxIndx){
    *maxIndx = 0;
    for(int i = 0; i < size;i++){
        if(arr[*maxIndx] < arr[i]){
            *maxIndx = i;
        }
    }    
    *maxVal = arr[*maxIndx];
}