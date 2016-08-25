from distutils.core import setup, Extension, Command
import os, sys
import importlib.util

class MakeData(Command):
    user_options = [
        ('generator=', None, "generator"),
    ]

    def initialize_options(self):
        self.generator = None

    def finalize_options(self):
        if not self.generator or not os.path.exists(self.generator):
            print('File "%s" does not exist' % self.generator)
            sys.exit(1)


    def run(self):
        exec(open(self.generator, "rb").read())

        spec = importlib.util.spec_from_file_location("polygon", self.generator)
        polygon = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(polygon)

        with open('polygon_data.c_tpl') as f:
            data = f.read()

        ph1 = ''
        ph2 = ''
        for idx, points in enumerate(polygon.all_polygons):
            ph1 += "static point_list polygon%s = {%s};\n" % (
                idx,
                ','.join("{%s, %s}" % (p[0], p[1]) for p in points)
            )
            ph2 += 'static Edge p%s  =   {%s, %s, %s, %s};\n' % (
                idx,
                min(p[0] for p in points),
                max(p[0] for p in points),
                min(p[1] for p in points),
                max(p[1] for p in points),
            )

        ph3 = ',\n'.join(
            '{(point_list*)polygon%s,  sizeof(polygon%s)/ sizeof(polygon%s[0]) , &p%s}' % (
                idx, idx, idx, idx
            ) for idx, _ in enumerate(polygon.all_polygons)
        )

        data = data.replace('//__PLACEHOLDER_1__', ph1)
        data = data.replace('//__PLACEHOLDER_2__', ph2)
        data = data.replace('//__PLACEHOLDER_3__', ph3)

        with open('polygon_data.c', 'w') as f:
            f.write(data)


setup(
    name='lesson_one',
    description='',
    ext_modules=[
        Extension('my_module', sources=[
            'my_module.c',
            'helper.c',
            'polygon.c',
            'noddy.c',
            'bullet.c',
        ])
    ],
    cmdclass={
        'make_data': MakeData,
    }
)
