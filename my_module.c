#include <Python.h>
#include <stdio.h>

static PyObject* my_func(PyObject *self, PyObject *args, PyObject *kwargs )
{
    double a = 0;
    double b = 0;
    double c = 0;
    static char *keywords[] = {"a", "b", "c", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddd", keywords, &a, &b, &c))
    {
        return NULL;
    }

    return PyFloat_FromDouble(a + b + c);
}

static PyMethodDef my_module_methods[] = { 
    {   
        "my_func",
        my_func,
        METH_VARARGS | METH_KEYWORDS,
        "docs"
    },  
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef my_module_definition = { 
    PyModuleDef_HEAD_INIT,
    "my_module",
    "docs",
    -1, 
    my_module_methods
};

PyMODINIT_FUNC PyInit_my_module(void)
{
    Py_Initialize();
    return PyModule_Create(&my_module_definition);
}
