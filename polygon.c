#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polygon_data.c"


int polygon_in_polygon(double x, double y, int polygon_idx){

    if (
        x < all_polygons[polygon_idx].edge->x_min ||
        x > all_polygons[polygon_idx].edge->x_max ||
        y < all_polygons[polygon_idx].edge->y_min ||
        y > all_polygons[polygon_idx].edge->y_max
    )
        return 0;

    int k;
    int c=0;
    int cnt = all_polygons[polygon_idx].el_count;
    for(k=0; k < cnt; k++){
        int px = **(*all_polygons[polygon_idx].mtp + k);
        int py = *(*(*all_polygons[polygon_idx].mtp + k) + 1);

        int px_prev, py_prev;
        if(k==0){
            px_prev = **(*all_polygons[polygon_idx].mtp + cnt-1);
            py_prev = *(*(*all_polygons[polygon_idx].mtp + cnt-1) + 1);
        }else{
            px_prev = **(*all_polygons[polygon_idx].mtp + k-1);
            py_prev = *(*(*all_polygons[polygon_idx].mtp + k-1) + 1);
        }
        if (
            ((py <= y && y < py_prev) || (py_prev <= y && y < py)) && 
            (x > (px_prev-px) * (y-py) / (py_prev-py) + px)
        ){
            c = 1 - c;
        }
    }

    return c % 2;
}
