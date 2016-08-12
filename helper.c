#include "math.h"
#include <stdio.h>


double helper_distance(float x1, float y1, float x2, float y2) 
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}


float * helper_resolve_line(float x1, float y1, float x2, float y2)
{
    if (x1 == x1){
        float result[2] = {0, 0}; /* vertical */
        return result;
    }

    float K, B;

    K = (y2 - y1) / (x2 - x1);
    B = y2 - K * x2;
    float result[2] = {K, B};
    return result;
}
