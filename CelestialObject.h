#include <cmath>
#include <string>
#include <iostream>

#define DNGP 27.13
#define ANGP 771.4
#define LNCP 122.93314

using namespace std;

//The object that will hold the data for each datapoint
class CelestialObject {

    public:
    string name = "\0";

    //fundamental properties
    float dist, plax, pMotion;

    //Equitorial coordinates
    float declination, rightAscension;

    //Galactocentric coordinates
    float longitude, latitude;

    //Create object without a name
    CelestialObject(float ndist, float nplax, float npMotion, float ndeclination, float nrightAscension) {
        dist = ndist;
        plax = nplax;
        pMotion = npMotion;
        declination  = ndeclination;
        rightAscension = nrightAscension;
    }

    //Create object without a name
    CelestialObject(string nname, float ndist, float nplax, float npMotion, float ndeclination, float nrightAscension) {
        name = nname;
        dist = ndist;
        plax = nplax;
        pMotion = npMotion;
        declination  = ndeclination;
        rightAscension = nrightAscension;
    }

    //Update the galactocentric coordinates with the current equatorial coordinates
    void eqTOgc() {
        //Conversion equations from equatorial to galactocentric
        latitude = asin(sin(DNGP)*sin(declination) + cos(DNGP)*cos(declination)*cos(rightAscension-ANGP));
        longitude = LNCP - asin((cos(declination)*sin(rightAscension-ANGP))/(cos(latitude)));
    }

    //Print helper
    void print() {
        if(name!="\0") {
            cout << name << ": ";
            cout << dist << " : " << plax << " : " << pMotion << '\n';
        } else {
            cout << dist << " : " << plax << " : " << pMotion << '\n';
        }
    }
};