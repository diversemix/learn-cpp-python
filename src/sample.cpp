#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>

/**
 * Sample shared library for binding to Python
 *
 * Referneces:
 *  - https://docs.python.org/3/extending/extending.html
 *  - https://intermediate-and-advanced-software-carpentry.readthedocs.io/en/latest/c++-wrapping.html
 *
 */

/**
 * hello - an example of a cpp function you wish to wrap and share with Pythoneers
 */
char * hello(char * what) {
    const char * prefix = "hello ";

    size_t prefix_len = strlen(prefix);
    size_t n = strlen(what) + prefix_len;

    char * tmp = (char *)malloc(n);
    memset(tmp, 0, n);
    strncpy(tmp, prefix, prefix_len);
    strncpy(tmp+prefix_len, what, strlen(what));
    return tmp;
}

/**
 * hello_wrapper - an example wrapper to make it exportable.
 */
extern "C" {PyObject *hello_wrapper(void *, PyObject *, PyObject *);}
PyObject * hello_wrapper(PyObject * self, PyObject * args)
{
  char * input;
  char * result;
  PyObject * ret;

  // parse arguments
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // run the actual function
  result = hello(input);

  // build the resulting string into a Python object.
  ret = PyUnicode_FromString(result);
  free(result);

  return ret;
}

/**
 * List of methods to export.
 */
static PyMethodDef CppSampleMethods[] = {
 { "hello", hello_wrapper, METH_VARARGS, "Say hello" },
 { NULL, NULL, 0, NULL }
};

/**
 * Definition of this Module.
 */
static struct PyModuleDef _sampleModule =
{
    PyModuleDef_HEAD_INIT,
    "cpp_sample",               /* name of module */
    "nothing to see here!",     /* module documentation, may be NULL */
    -1,
    (PyMethodDef *)CppSampleMethods
};

/**
 * The initialization function that python will look for.
 */
PyMODINIT_FUNC PyInit_cpp_sample(void)
{
    return PyModule_Create(&_sampleModule);
}
