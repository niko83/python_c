#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int (point_list)[][2];

static point_list polygon0 = {{0,0}, {100,0}, {100, 100}, {0, 100}};
static point_list polygon1 = {{0,0}, {1000,0}, {1000, 1000}, {0, 1000}};
static point_list polygon2 = {{0,0}, {10000,0}, {10000, 10000}, {0, 10000}};

static struct {
  point_list *mtp;
  int el_count;
} all_polygons[] = {
  {(point_list*)polygon0, sizeof(polygon0)/sizeof(polygon0[0])},
  {(point_list*)polygon1, sizeof(polygon1)/sizeof(polygon1[0])},
  {(point_list*)polygon2, sizeof(polygon2)/sizeof(polygon2[0])},
};



int polygon_in_polygon(double x, double y, int polygon_idx){

    int k;
    int c=0;
    for(k=0; k<all_polygons[polygon_idx].el_count; k++){
        int px = **(*all_polygons[polygon_idx].mtp + k);
        int py = *(*(*all_polygons[polygon_idx].mtp + k) + 1);

        int px_prev, py_prev;
        if(k==0){
            px_prev = **(*all_polygons[polygon_idx].mtp + all_polygons[polygon_idx].el_count-1);
            py_prev = *(*(*all_polygons[polygon_idx].mtp + all_polygons[polygon_idx].el_count-1) + 1);
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

    /* int *polygon;  */
    /* switch(polygon_idx){ */
        /* case 0: */
            /* polygon[sizeof(polygon0)/sizeof(polygon0[0])] = polygon0; */
        /* case 1: */
            /* polygon[sizeof(polygon1)/sizeof(polygon1[0])] = polygon1; */
        /* case 2: */
            /* polygon[sizeof(polygon2)/sizeof(polygon2[0])] = polygon2; */
        /* default: */
            /* polygon[sizeof(polygonX)/sizeof(polygonX[0])] = polygonX; */
            /* printf("polygon not found"); */
    /* } */

    return 1;

}
