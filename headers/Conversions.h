#include <cmath>
#include "Coordinates.h"

#define DNGP 27.12825
#define ANGP 192.85948
#define LNCP 32.93192

#define DEGTORAD (3.14159265358979323846/180.0)
#define RADTODEG (1.0/DEGTORAD)

#define SUNTOCENTER (8.4928586)

double asinDEG(double x) {
    return RADTODEG * asin(x);
}

double sinDEG(double x) {
    return sin(DEGTORAD * x);
}

double cosDEG(double x) {
    return cos(DEGTORAD * x);
}

double atan2DEG(double x, double y) {
    return RADTODEG * atan2(x,y);
}

void eqTOgc(Coordinate coord) {
        //Conversion equations from equatorial to galactic
        double DEC = coord.DEC;
	double RA = coord.RA;

	coord.b = asinDEG( sinDEG(DNGP)*sinDEG(DEC) + cosDEG(DNGP) * cosDEG(DEC) * cosDEG(DEC) * cosDEG(RA - ANGP));

       	double y = cosDEG(DEC) * sinDEG(RA - ANGP);
        double x = sinDEG(DEC) * cosDEG(DNGP) - cosDEG(DEC) * sinDEG(DNGP) * cosDEG(RA - ANGP);

        coord.l = LNCP + atan2DEG(y, x);

}

void gcTOeq(Coordinate coord) {
	//Conversion equations from galactic to equatorial
	double l = coord.l;
	double b = coord.b;

	coord.DEC =  asinDEG(sinDEG(b)*sinDEG(DNGP) + cosDEG(b)*cosDEG(DNGP)*sinDEG(l-LNCP));

	double y = cosDEG(b) * cosDEG(l-LNCP);
	double x = sinDEG(b) * cosDEG(DNGP) - cosDEG(b) * sinDEG(DNGP) * sinDEG(l-LNCP);

	coord.RA = ANGP + atan2DEG(y,x);
}

//Gets the distance to search for the degree
double getDist(double l) {
	double n = 4.0;
	double a = pow(SUNTOCENTER,-n);
	double b = a/10;
	double base = (1.0)/(a*pow(cosDEG(l),n) + b*pow(sinDEG(l),n));
	return pow(base,(1.0/n));
}
