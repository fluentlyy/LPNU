#include <stdio.h>

int main(void) {
    int U[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = sizeof(U) / sizeof(U[0]);

    printf("{}\n");

    for(int i = 0; i < count; i++){
        printf("{%d}\n", U[i]);
        for(int j = 0; j < count; j++){
            printf("{%d, %d}\n", U[i], U[j]);
            for(int k = 0;k < count;k++){
                printf("{%d, %d, %d}\n", U[i], U[j], U[k]);
            }
        }
    }

    return 0;
}