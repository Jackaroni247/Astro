#include <cmath>
#include <string>
#include <iostream>

#define DNGP 27.13
#define ANGP 192.85
#define LNCP 122.93314

#define DEGTORAD (3.14159265358979323846/180.0)
#define RADTODEG (1.0/DEGTORAD)


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
        latitude = RADTODEG*asin(sin(DEGTORAD*DNGP)*sin(DEGTORAD*declination) + cos(DEGTORAD*DNGP)*cos(DEGTORAD*declination)*cos(DEGTORAD*(rightAscension-ANGP)));
        longitude = LNCP - RADTODEG*asin((cos(DEGTORAD*declination)*sin(DEGTORAD*(rightAscension-ANGP)))/(cos(DEGTORAD*latitude)));
    }

    //print the motion in the sky
    void printMot() {
        if(name!="\0") {
            cout << name << ": ";
            cout << dist << " : " << plax << " : " << pMotion << '\n';
        } else {
            cout << dist << " : " << plax << " : " << pMotion << '\n';
        }
    }
    
    //print the Galactocentric Coords
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
