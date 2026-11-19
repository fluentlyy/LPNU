#include <stdio.h>
#define OPTION 2

int main(){
    int x, y, z, w;
    printf("Enter x, y and z(x y z):");
    scanf("%d %d %d", &x, &y, &z);
    #if OPTION == 1
        w = ((x && y) && (x || z)) && (!x != y);
    #else
        w = ((x || y) && (z || y)) && (z || x);
    #endif
    printf("Result: %d", w);
    return 0;
}