#include <math.h>

int calc_y2(double x, double *py){
    *py = sqrt(1 - cos(2*x));
    if(*py < 0) return  -1;
    if(*py == 0) return 0;
    if(*py > 0) return 1;
}