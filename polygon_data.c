
typedef struct {
    int x;
    int y;
} Point;

typedef Point (point_list)[];

typedef struct {
    int x_min;
    int x_max;
    int y_min;
    int y_max;
} Edge;

static point_list polygon0 = {{0,0}, {100,0}, {100, 100}, {0, 100}};
static point_list polygon1 = {{0,0}, {1000,0}, {1000, 1000}, {0, 1000}};
static point_list polygon2 = {{1,2}, {10030,4}, {10050, 10060}, {7, 10080}};

static Edge p0 = {0, 100, 0, 100};
static Edge p1 = {0, 1000, 0, 1000};
static Edge p2 = {0, 10000, 0, 10000};

static struct {
  point_list *mtp;
  int el_count;
  Edge *edge;
} all_polygons[] = {
    {(point_list*)polygon0, sizeof(polygon0)/sizeof(polygon0[0]), &p0},
    {(point_list*)polygon1, sizeof(polygon1)/sizeof(polygon1[0]), &p1},
    {(point_list*)polygon2, sizeof(polygon2)/sizeof(polygon2[0]), &p2},
};
