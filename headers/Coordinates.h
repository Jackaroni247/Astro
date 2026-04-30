#define EQUATORIAL 0;
#define GALACTIC 1;

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

};
