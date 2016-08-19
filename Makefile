make:
	rm -rf build; clear; python setup.py build install; python -c"import my_module; print(my_module.in_polygon(700, 700, 0));"
perform_test:
	bash -c "\
	    python setup.py build; python setup.py install; \
	    time python test.py 0 $(count); \
	    time python test.py 1 $(count)"
