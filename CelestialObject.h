#include <cmath>
#include <string>
#include <iostream>

#define DNGP 27.12825
#define ANGP 192.85948
#define LNCP 32.93192

#define DEGTORAD (3.14159265358979323846/180.0)
#define RADTODEG (1.0/DEGTORAD)


using namespace std;

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

//The object that will hold the data for each datapoint
class CelestialObject {

    public:
    string name = "\0";

    //fundamental properties
    double dist, plax, pMotion;

    //Equitorial coordinates
    double declination, rightAscension;

    //Galactocentric coordinates
    double longitude, latitude;

    //Create object without a name
    CelestialObject(double ndist, double nplax, double npMotion, double ndeclination, double nrightAscension) {
        dist = ndist;
        plax = nplax;
        pMotion = npMotion;
        declination  = ndeclination;
        rightAscension = nrightAscension;
    }

    //Create object without a name
    CelestialObject(string nname, double ndist, double nplax, double npMotion, double ndeclination, double nrightAscension) {
        name = nname;
        dist = ndist;
        plax = nplax;
        pMotion = npMotion;
        declination  = ndeclination;
        rightAscension = nrightAscension;
    }

    //Update the galactic coordinates with the current equatorial coordinates
    void eqTOgc() {
        //Conversion equations from equatorial to galactic
        latitude = asinDEG( sinDEG(DNGP)*sinDEG(declination) + cosDEG(DNGP) * cosDEG(declination) * cosDEG(rightAscension - ANGP));
        
        double y = cosDEG(declination) * sinDEG(rightAscension - ANGP);
        double x = sinDEG(declination) * cosDEG(DNGP) - cosDEG(declination) * sinDEG(DNGP) * cosDEG(rightAscension - ANGP);
        
        longitude = LNCP + atan2DEG(y, x);
    }

    //print the Motion in the sky
    void printMot() {
        if(name!="\0") {
            cout << name << ": ";
            cout << dist << " : " << plax << " : " << pMotion << '\n';
        } else {
            cout << dist << " : " << plax << " : " << pMotion << '\n';
        }
    }
    
    //print the Galactic Coords
        void printGC() {
        if(name!="\0") {
            cout << name << ": ";
            cout << dist << " : " << longitude << " : " << latitude << '\n';
        } else {
            cout << dist << " : " << longitude << " : " << latitude << '\n';
        }
    }
    //Print the Equatorial Coords
    void printEQ() {
        if(name!="\0") {
            cout << name << ": ";
            cout << dist << " : " << declination << " : " << rightAscension << '\n';
        } else {
            cout << dist << " : " << declination << " : " << rightAscension << '\n';
        }
    }
};

int main(){
    CelestialObject bound1("Bound1", 1.0, 1.0, 1.0, -45, 16*15);
    CelestialObject bound2("Bound1", 1.0, 1.0, 1.0, -10, 19*15);
    bound1.eqTOgc();
    bound1.printEQ();
    bound1.printGC();
    bound2.eqTOgc();
    bound2.printEQ();
    bound2.printGC();
    return 1;
}
