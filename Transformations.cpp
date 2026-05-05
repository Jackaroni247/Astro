#include <pybind11/pybind11.h>
#include <Python.h>
#include "headers/CelestialObject.h"
#include "headers/OortConstants.h"

using namespace std;
namespace py = pybind11;

float transform(){
    cout << getDist(0);
    return 1.0;
}

PYBIND11_MODULE(Transformations, Module) {
	Module.doc() = "Python module written in C++ for astrophysics transformations";

	Module.def("transform", &transform);
}
