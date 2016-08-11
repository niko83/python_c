make:
	clear; python setup.py build install; python -c"import my_module; print(my_module.my_func(10, b=100, c=2));"
