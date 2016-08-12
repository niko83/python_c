import sys
import math

if sys.argv[1] == '1':
    print('='*50)
    print('Run C implementation')
    from my_module import distance, resolve_line
else:
    print('='*50)
    print('Python implementation')
    def distance(p1, p2):
        return math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)

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
    distance((123, 232), (1223, 3424))
    resolve_line((123, 232), (1223, 3424))
