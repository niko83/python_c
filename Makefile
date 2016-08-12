make:
	clear; python setup.py build install; python -c"import my_module; print(my_module.resolve_line((10, 12), (23,345)));"
perform_test:
	bash -c "\
	    python setup.py build; python setup.py install; \
	    time python test.py 0 $(count); \
	    time python test.py 1 $(count)"
