from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("cpp_sample", ["src/sample.cpp"])

setup(name = "cpp_sample", ext_modules=[extension_mod])

