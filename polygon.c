#include <stdio.h>
#include <stdlib.h>

const int polygon[][2] = {
    {344, 298},
    {375, 315},
    {420, 369},
    {425, 410},
    {388, 449},
    {345, 448},
    {306, 453},
    {259, 397},
    {260, 384},
    {254, 376},
    {271, 358},
    {276, 343},
    {304, 321},
    {304, 308},
};


int *polygon_get_polygon(double x, double y, int *array_len){

    *array_len = sizeof(polygon)/sizeof(int)/2;
    int *result = malloc(*array_len * sizeof(int));

    for(int i = 0; i<*array_len; i++){
        result[i] = polygon[i][0];
    }
    return result;

}
