#include <Python.h>
#include <stdio.h>
#include "helper.h"
#include "polygon.h"

static PyObject* my_func(PyObject *self, PyObject *args, PyObject *kwargs)
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

static PyObject* distance(PyObject *self, PyObject *args)
{
    float x1, y1, x2, y2;
    if (!PyArg_ParseTuple(args, "(ff)(ff)", &x1, &y1, &x2, &y2)) {
        return NULL;
    }
    return PyFloat_FromDouble(helper_distance(x1, y1, x2, y2));
}

static PyObject* resolve_line(PyObject *self, PyObject *args)
{
    double x1, y1, x2, y2;
    double result[2];
    if (!PyArg_ParseTuple(args, "(dd)(dd)", &x1, &y1, &x2, &y2)) {
        return NULL;
    }

    helper_resolve_line(x1, y1, x2, y2, result);
    if (result == 0 && result == 0){
        return Py_BuildValue("(ss)", NULL, NULL);
    }else{
        return Py_BuildValue("dd", result[0], result[0]);
    }
}


static PyObject* in_polygon(PyObject *self, PyObject *args)
{
    double x, y; 
    int polygon_idx;
    if (!PyArg_ParseTuple(args, "ddi", &x, &y, &polygon_idx)) {
        return NULL;
    }

    return Py_BuildValue("i", polygon_in_polygon(x, y, polygon_idx));

    /* PyObject *lst = PyList_New(array_len); */

    /* printf("Array len: %d\n", array_len); */
    /* int i; */
    /* for (i=0; i < array_len; i++) { */
        /* [> printf("val: %d\n", result[i]); <] */
        /* PyObject *num = PyFloat_FromDouble(result[i]); */
        /* PyList_SET_ITEM(lst, i, num);  */
    /* } */
    /* free(result); */

    /* return lst; */
}

static PyMethodDef my_module_methods[] = { 
    {"my_func", my_func, METH_VARARGS | METH_KEYWORDS, "docs" },  
    {"distance", distance, METH_VARARGS, "docs"},
    {"resolve_line", resolve_line, METH_VARARGS, "docs"},
    {"in_polygon", in_polygon, METH_VARARGS, "docs"},
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
