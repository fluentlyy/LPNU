#include <stdio.h>
#define OPTION 2

int main(){
    int x = 0, y = 1, z = 1, w;
    #if OPTION == 1
        w = ((x && y) && (x || z)) && (!x != y);
    #else
        w = ((x || y) && (z || y)) && (z || x);
    #endif
    printf("Result: %d", w);
    return 0;
}