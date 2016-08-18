import sys
import math
import random

if sys.argv[1] == '1':
    print('='*50)
    print('Run C implementation')
    from my_module import distance, resolve_line, in_polygon
else:
    print('='*50)
    print('Python implementation')
    def distance(p1, p2):
        return math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)

    xp = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
    yp = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
    def in_polygon(x, y, idx):
        xp[0]
        c=0
        for i in range(len(xp)):
            if (
                (
                    (yp[i]<=y<yp[i-1]) or (yp[i-1]<=y<yp[i])
                ) and (
                    x > (xp[i-1]-xp[i]) * (y-yp[i]) / (yp[i-1]-yp[i]) + xp[i]
                )
            ):
                c = 1 - c

        return c % 2 == 1

    def resolve_line(p1, p2):
        x1 = p1[0]
        y1 = p1[1]
        x2 = p2[0]
        y2 = p2[1]

        if x2 == x1:
            return None, None  # vertical
        K = (y2 - y1) / (x2 - x1)
        B = y2 - K * x2
        return K, B

for i in range(int(sys.argv[2])):
    #  distance((123, 232), (1223, 3424))
    #  resolve_line((123, 232), (1223, 3424))
    in_polygon(random.randint(0, 2000), random.randint(0, 1000), 0)
