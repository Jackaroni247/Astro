#define EQUATORIAL 0;
#define GALACTIC 1;

#include "Conversions.h"

class Coordinate {
	public:
	bool MODE = EQUATORIAL;
	double RA, DEC;
	double l, b;

	Coordinate() {
		RA = 0.0;
		DEC = 0.0;
		l = 0.0;
		b = 0.0;
	}

	Coordinate(bool setMODE, double n1, double n2) {
		if(setMODE) {
			l = n1;
			b = n2;
		} else {
			RA = n1;
			DEC = n2;
		}
	}

	//Conversion equations from equatorial to galactic
	void eqTOgc() {
		b = asinDEG( sinDEG(DNGP)*sinDEG(DEC) + cosDEG(DNGP) * cosDEG(DEC) * cosDEG(RA - ANGP));

		double y = cosDEG(DEC) * sinDEG(RA - ANGP);
		double x = sinDEG(DEC) * cosDEG(DNGP) - cosDEG(DEC) * sinDEG(DNGP) * cosDEG(RA - ANGP);

		l = LNCP + atan2DEG(y,x);
	}

	//Conversion equations from galactic to equatorial
	void gcTOeq() {
		DEC = asinDEG(sinDEG(b)*sinDEG(DNGP) + cosDEG(DNGP)*sinDEG(l-LNCP));

		double y = cosDEG(b) * cosDEG(l-LNCP);
		double x = sinDEG(b) * cosDEG(DNGP) - cosDEG(b) * sinDEG(DNGP) * sinDEG(l-LNCP);

		RA = ANGP + atan2DEG(y,x);
	}

	double getEQ_RA() {
		return RA;
	}

	double getEQ_DEC() {
		return DEC;
	}

};
