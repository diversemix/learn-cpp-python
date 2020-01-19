# learn-cpp-python
Skeleton example of Python linkage to C++

## Building
This uses a `Makefile` to wrap the `setup.py` functionality. To build/install and test simply use:

```{bash}
make
```

There is also a `requirements.sh` script which will ensure you have the some
of the more common requirements when building and developing C++ bindings.
These are:

- [C++17](https://en.cppreference.com/w/cpp)
- [boost](https://www.boost.org/)
- [swig](http://www.swig.org/)

## Other Things to look at

- [PEP-0513](https://www.python.org/dev/peps/pep-0513/)
- [PEP-0571](https://www.python.org/dev/peps/pep-0571/)
- [manylinux](https://github.com/pypa/manylinux)
