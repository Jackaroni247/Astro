#include <Eigen/Dense>
#include <cmath>
#include <string>
#include <iostream>
#include <numbers>

#include "Coordinates.h"

using namespace std;

//The object that will hold the data for each datapoint
class CelestialObject {

    public:
    Coordinate GACoords, HCCoords, GCCoords;
	string name;

    Eigen::MatrixXd covarianceGA;
    Eigen::MatrixXd covarianceGC;

    //Create object without a name
    CelestialObject(Coordinate ncoords) {
        GACoords = ncoords;
    }

    //Create object without a name
    CelestialObject(string nname, Coordinate ncoords) {
        name = nname;
        GACoords = ncoords;
    }
};
