#include <cmath>

#define DNGP 27.12825
#define ANGP 192.85948
#define LNCP 32.93192

#define VLSR 233

#define SUNPECULIARMOTION 12.2

#define DEGTORAD (3.141592653589/180.0)
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

//Gets the distance to search for the degree
double searchDist(double l) {
	double n = 2.0;
	double a = pow(14.0,n);
	double b = pow(2.0,n);
	double d = 14.0-SUNTOCENTER;
	double numerator = -b*d + sqrt(
				a*b*b*pow(cosDEG(l),2) +
				a*a*b*pow(sinDEG(l),2) -
				a*b*d*d*pow(sinDEG(l),2)
				);
	double denominator = b*pow(cosDEG(l),2) + a*pow(sinDEG(l),2);
	return (numerator/denominator);
}

double calc_Galactic_Radius(double l, double b, double d) {
	return sqrt(pow(SUNTOCENTER,2) + pow(d*cosDEG(b),2) - 2*SUNTOCENTER*cosDEG(b)*cosDEG(l));
}


//Calculate the circular velocity of an object
double calcCV(double pm_L, double l, double b, double d) {
	double R = calc_Galactic_Radius(l,b,d);
	double CV = (SUNTOCENTER/R)*(pm_L * cosDEG(b) + VLSR + SUNPECULIARMOTION);
	return CV;
}

//Calculate the proper motion in the longitude direction
double calc_PM_L(double RA, double DEC, double pmRA, double pmDEC) {
	double a = sinDEG(DNGP) * cosDEG(DEC) - cosDEG(DNGP) * sinDEG(DEC) * cosDEG(RA - ANGP);
	double b = cosDEG(DNGP) * sinDEG(RA-ANGP);
	return a*(pmRA*cos(DEC)) + b*pmDEC;
}
