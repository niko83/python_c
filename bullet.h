#define M_PI 3.14159265358979323846

typedef struct {
    double life_limit;
    double able_to_make_tracing;
    double current_speed_x;
    double current_speed_y;
    double current_position_x;
    double current_position_y;
    int approx_x;
    int approx_y;
} Result;


void bullet_calculate_position(
        double FRAME_INTERVAL,
        int ricochet,
        Result * result
);
