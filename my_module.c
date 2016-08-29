#include <Python.h>
#include <stdio.h>
#include "helper.h"
#include "noddy.c"



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


static PyMethodDef my_module_methods[] = { 
    {"distance", distance, METH_VARARGS, "docs"},
    {"resolve_line", resolve_line, METH_VARARGS, "docs"},
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
