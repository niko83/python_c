#include "math.h"
#include "stdlib.h"
#include "helper.h"
#include "polygon_data.c"
 
#define M_PI 3.14159265358979323846

typedef struct {
    double life_limit;
    double able_to_make_tracing;
    double current_speed_x;
    double current_speed_y;
    double current_position_x;
    double current_position_y;
    double approx_x;
    double approx_y;
} Result;

const int CELL_STEP = 80;

double vector_get_angle(double x, double y){
    
    if (x == 0){
        if (y == 0){
            return 0;
        } else if (y > 0){
            return M_PI/2;
        }else{
            return M_PI * 3 / 2;
        }
    }

    double angle = abs(atan(y / x));

    if (x < 0){
        if (y < 0){
            return M_PI + angle;
        }else{
            return M_PI - angle;
        }
    }else{
        if (y < 0){
            return 2 * M_PI - angle;
        } else {
            return angle;
        }
    }
}


double get_intersection_angle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y, double *angle_intersection){
    
    double x;

    double line1[2], line2[2];
    helper_resolve_line(p1x, p1y, p2x, p2y, line1);
    helper_resolve_line(p3x, p3y, p4x, p4y, line2);

    if (line1[0] == line2[0]){
        return 0;
    } else if (line1[0] == 0 && line1[1] == 0){
        x = (double) p1x;
    } else if (line2[0] == 0 && line2[1]==0){
        x = (double) p3x;
    } else {
        x = (line2[1] - line1[1])/(line1[0] - line2[0]);
    }

    if ((p1x<=x && x<=p2x) || (p2x<=x && x<=p1x)) {
        double nil_vector_ship_x, nil_vector_ship_y, nil_vector_polygon_x, nil_vector_polygon_y;


        double ship_angle = vector_get_angle(p2x - p1x, p2y - p1y); 

        double polygon_angle = vector_get_angle(p4x - p3x, p4y - p3y);

        if (polygon_angle >= M_PI){
            polygon_angle -= M_PI;
        }

       *angle_intersection = ship_angle - polygon_angle;
        while (*angle_intersection > M_PI/2){
            *angle_intersection -= M_PI;
        }
        return 1;
    }
    return 0;
}

int get_angle_collision(double x1, double y1, double x2, double y2, int polygon_idx, double *result){

    int k;
    int cnt = all_polygons[polygon_idx].el_count;
    for(k=0; k< cnt; k++){

        int px = (*all_polygons[polygon_idx].mtp+k)->x;
        int py = (*all_polygons[polygon_idx].mtp+k)->y;

        int px_prev, py_prev;
        if(k==0){
            px_prev = (*all_polygons[polygon_idx].mtp+cnt-1)->x;
            py_prev = (*all_polygons[polygon_idx].mtp+cnt-1)->y; 
        }else{
            px_prev = (*all_polygons[polygon_idx].mtp+k-1)->x;
            py_prev = (*all_polygons[polygon_idx].mtp+k-1)->y; 
        }
           
        if (get_intersection_angle(x1, y1, x2, y2, px, py, px_prev, py_prev, &result) == 1){
            return 1;
        }
    }
    return 0;

}

void calculate_position(
        double FRAME_INTERVAL,
        int ricochet,
        Result result
){
    if (result.life_limit < FRAME_INTERVAL){
        result.life_limit = -1;
        return;
    }
    result.life_limit -= FRAME_INTERVAL;

    if (result.able_to_make_tracing > -100){
        result.able_to_make_tracing += FRAME_INTERVAL;
    }

    if (result.current_speed_x == result.current_speed_y == 0){
        return;
    }

    double candidat_position_x = result.current_position_x + result.current_speed_x * FRAME_INTERVAL;
    double candidat_position_y = result.current_position_y - result.current_speed_y * FRAME_INTERVAL;

    result.approx_x = floor(candidat_position_x/CELL_STEP);
    result.approx_y = floor(candidat_position_y/CELL_STEP);

        /* try: */
            /* if polygon_cell[self.approx_x][self.approx_y]: */
                /* polygon_idx = maps.get_polygon_world_collision(candidat_position_x, candidat_position_y) */
            /* else: */
                /* polygon = None */
        /* except IndexError: */
            /* self.approx_x = self.approx_y = 0 */
            /* has_world_collision = True */
            /* polygon_idx = 0

    int polygon_idx = 1;

    if (polygon_idx && ricochet==0){
        result.life_limit = -1;
        return;
    }

    double angle;
    if (polygon && ricochet==1){
        
        if (get_angle_collision(result.current_position_x, result.current_position_y, candidat_position_x, candidat_position_y, polygon_idx, &angle) == 1){
            
        }else{
            result.life_limit = -1;  // выстрел прямо в скале
            return;
        }

        /* self.current_speed.reinit( */
            /* length=self.current_speed.length, */
            /* angle=angle*2 + self.current_speed.angle() */
        /* ) */
        return;
    }

}
