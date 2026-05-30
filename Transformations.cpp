#include <pybind11/pybind11.h>
#include "headers/CelestialObject.h"
#include "headers/OortConstants.h"
#include "headers/Clustering.h"

using namespace std;
namespace py = pybind11;

PYBIND11_MODULE(Transformations, handle) {
	handle.doc() = "Python module written in C++ for astrophysics transformations";

	py::class_<Coordinate>(handle, "Coordinate")
	.def(py::init<bool,double,double>())
	.def("getEQ_RA", &Coordinate::getEQ_RA)
	.def("getEQ_DEC", &Coordinate::getEQ_DEC)
	.def("gcTOeq", &Coordinate::gcTOeq)
	;


	py::class_<CelestialObject>(handle, "CelestialObject")
	.def(py::init<double,double,double,Coordinate>())
	;

	handle.def("searchDist", &searchDist);
	handle.def("calcCV", &calcCV);
	handle.def("calc_PM_L", &calc_PM_L);
	handle.def("calc_Galactic_Radius", &calc_Galactic_Radius);
	handle.def("similarityMatrix", &similarityMatrix);
}
