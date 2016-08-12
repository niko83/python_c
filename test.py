import sys
import math

if sys.argv[1] == '1':
    print('='*50)
    print('Run C implementation')
    from my_module import distance
else:
    print('='*50)
    print('Python implementation')
    def distance(p1, p2):
        return math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)

for i in range(int(sys.argv[2])):
    distance((123,232), (1223,3424))
