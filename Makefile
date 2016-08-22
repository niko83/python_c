make:
	rm -rf build; clear; python setup.py build install; python test2.py
perform_test:
	bash -c "\
	    python setup.py build; python setup.py install; \
	    time python test.py 0 $(count); \
	    time python test.py 1 $(count)"
