import my_module

class A(object):
    def __init__(self, x):
        self.life_limit=100
        self.able_to_make_tracing=2
        self.current_speed_x=200
        self.current_speed_y=250
        self.current_position_x=1100
        self.current_position_y=1100
        self.approx_x=60
        self.approx_y=60
        self.ricochet = 1

a = A(111)
my_module.calculate_position(0.002, a)


print(a.life_limit)
print(a.able_to_make_tracing)
print(a.current_speed_x)
print(a.current_speed_y)
print(a.current_position_x)
print(a.current_position_y)
print(a.approx_x)
print(a.approx_y)
print(a.ricochet)
