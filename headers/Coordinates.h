#define EQUATORIAL 0
#define GALACTIC 1

#include "Conversions.h"

using namespace Eigen;

class Coordinate {
	public:
	bool MODE = EQUATORIAL;
	VectorXd PSVector;

	Coordinate() = default;

	Coordinate(bool nMODE, VectorXd nPSVector) {
		MODE = nMODE;
		PSVector = nPSVector;
	}

	Coordinate(bool nMODE, double ra, double dec, double plax, double pmra, double pmdec, double rv) : MODE(nMODE), PSVector(6) {
		PSVector << ra,dec,plax,pmra,pmdec,rv;
	}
};
