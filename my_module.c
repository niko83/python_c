#include <Python.h>
#include <stdio.h>
#include "helper.h"
#include "polygon.h"
#include "noddy.c"
#include "bullet.h"


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
}


static PyObject* get_polygon_idx_collision(PyObject *self, PyObject *args)
{
    double x, y; 
    if (!PyArg_ParseTuple(args, "dd", &x, &y)) {
        return NULL;
    }

    return Py_BuildValue("i", polygon_get_polygon_idx_collision(x, y));
}


static PyObject* calculate_position(PyObject *self, PyObject *args)
{
    double FRAME_INTERVAL; 
    PyObject * obj;

    if (!PyArg_ParseTuple(args, "dO", &FRAME_INTERVAL, &obj)) {
        return NULL;
    }
    bullet_calculate_position(FRAME_INTERVAL, obj);
    return Py_BuildValue("s", NULL);
}

static PyMethodDef my_module_methods[] = { 
    {"my_func", my_func, METH_VARARGS | METH_KEYWORDS, "docs" },  
    {"distance", distance, METH_VARARGS, "docs"},
    {"resolve_line", resolve_line, METH_VARARGS, "docs"},
    {"in_polygon", in_polygon, METH_VARARGS, "docs"},
    {"get_polygon_idx_collision",  get_polygon_idx_collision, METH_VARARGS, "docs"},
    {"calculate_position",  calculate_position, METH_VARARGS, "docs"},
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
    PyObject* m; 

    noddy_NoddyType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&noddy_NoddyType) < 0)
        return NULL;

    m = PyModule_Create(&my_module_definition);
    if (m == NULL)
        return NULL;

    Py_INCREF(&noddy_NoddyType);
    PyModule_AddObject(m, "Noddy", (PyObject *)&noddy_NoddyType);
    return m;
}
