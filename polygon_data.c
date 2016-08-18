

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
