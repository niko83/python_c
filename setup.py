from distutils.core import setup, Extension

setup(
    name='lesson_one',
    description='',
    ext_modules=[
        Extension('my_module', sources=[
            'my_module.c',
            'helper.c',
            'polygon.c',
            'noddy.c',
        ])
    ],
)
