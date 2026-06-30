#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "headers/CelestialObject.h"
#include "headers/OortConstants.h"
#include "headers/Clustering.h"
#include "headers/KMeans.h"

using namespace std;
namespace py = pybind11;

void mainProcessing(const vector<CelestialObject>& dataVector) {
	kMeans(spectralMatrix(dataVector), 10);
}

PYBIND11_MODULE(Transformations, handle) {
	handle.doc() = "Python module written in C++ for astrophysics transformations"	  ;

	py::class_<Coordinate>(handle, "Coordinate")
	.def(py::init<bool,double,double,double,double,double,double>())
	;

	py::class_<CelestialObject>(handle, "CelestialObject")
	.def(py::init<Coordinate>())
	.def(py::init<string, Coordinate>())
	;

	handle.def("searchDist", &searchDist);
	handle.def("spectralMatrix", &spectralMatrix);
	handle.def("kMeans", &kMeans);
	handle.def("mainProcessing", &mainProcessing);
}
