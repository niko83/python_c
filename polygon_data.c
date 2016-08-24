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


static point_list polygon_fake = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
static point_list polygon2 = {{0, 0}, {3371, 0}, {3371, 50}, {0, 20}};
static point_list polygon3 = {{3371-50, 0}, {3371, 0}, {3371, 1889}, {3371-50, 1889}};
static point_list polygon4 = {{0, 1889-50}, {3371, 1889-50}, {3371, 1889}, {0, 1889}};
static point_list polygon5 = {{0, 0}, {50, 0}, {50, 1889}, {0, 1889}};

static Edge p_fake  =   {0, 1, 0, 1};
static Edge p2  =   {0, 3371, 0, 50};
static Edge p3  =   {3321, 3371, 0, 1889};
static Edge p4  =   {0, 3371, 1839, 1889};
static Edge p5  =   {0, 50, 0, 1889};



static struct {
  point_list *mtp;
  int el_count;
  Edge *edge;
} all_polygons[] = {
  {(point_list*)polygon_fake,  sizeof(polygon_fake)/ sizeof(polygon_fake[0]) , &p_fake},
  {(point_list*)polygon2,  sizeof(polygon2)/ sizeof(polygon2[0]) , &p2},
  {(point_list*)polygon3,  sizeof(polygon3)/ sizeof(polygon3[0]) , &p3},
  {(point_list*)polygon4,  sizeof(polygon4)/ sizeof(polygon4[0]) , &p4},
  {(point_list*)polygon5,  sizeof(polygon5)/ sizeof(polygon5[0]) , &p5},
};
