from distutils.core import setup, Extension, Command
import pickle
import os, sys
import importlib.util
from bitarray import bitarray



setup(
    name='lesson_one',
    description='',
    ext_modules=[
        Extension('my_module', sources=[
            'my_module.c',
            'helper.c',
            'noddy.c',
        ])
    ],
)
