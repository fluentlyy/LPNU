#include <stdio.h>

int main(void){
    int n;
    double max, min, average, sum = 0;

    printf("Enter amount of vector`s elements(at least 4): ");
    if(scanf("%d", &n) < 4){
        printf("Error\n");
        return 0;
    }
    

    double arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter a num: ");
        scanf("%lf", &arr[i]);

        if(i == 0){
            max = arr[0];
            min = arr[0];
        }else{
            if(max < arr[i] ) max = arr[i];

            if(min > arr[i]) min = arr[i];
        }
    }

    
    for(int i = 0; i < n; i++){
        if(arr[i] == max || arr[i] == min){
            arr[i] = 0;
        }

        sum += arr[i];

    }
    
    average = sum / (n - 2.0);
    printf("Result: %lf", average);


    return 0;
}