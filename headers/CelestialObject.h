#include <cmath>
#include <string>
#include <iostream>

#include "Conversions.h"

using namespace std;

//The object that will hold the data for each datapoint
class CelestialObject {

    public:
    string name = "\0";

    //fundamental properties
    double dist, plax, pMotion;

    Coordinate coords;

    //Create object without a name
    CelestialObject(double ndist, double nplax, double npMotion, Coordinate ncoords) {
        dist = ndist;
        plax = nplax;
        pMotion = npMotion;
        coords = ncoords;
    }

    //Create object without a name
    CelestialObject(string nname, double ndist, double nplax, double npMotion, Coordinate ncoords) {
        name = nname;
        dist = ndist;
        plax = nplax;
        pMotion = npMotion;
        coords = ncoords;
    }

    //Update the galactic coordinates with the current equatorial coordinates
    void convert() {
        //Conversion equations from equatorial to galactic
        eqTOgc(coords);
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
            cout << dist << " : " << coords.l << " : " << coords.b << '\n';
        } else {
            cout << dist << " : " << coords.l << " : " << coords.b << '\n';
        }
    }
    //Print the Equatorial Coords
    void printEQ() {
        if(name!="\0") {
            cout << name << ": ";
            cout << dist << " : " << coords.DEC << " : " << coords.RA << '\n';
        } else {
            cout << dist << " : " << coords.DEC << " : " << coords.RA << '\n';
        }
    }
};
