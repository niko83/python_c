make:
	clear; python setup.py build install; python -c"import my_module; print(my_module.get_polygon(10, 12));"
perform_test:
	bash -c "\
	    python setup.py build; python setup.py install; \
	    time python test.py 0 $(count); \
	    time python test.py 1 $(count)"
