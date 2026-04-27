#define DNGP 27.13
#define ANGP (12.0 * (360.0/24.0) + 51.4 * (360.0/(24.0*60.0)))
#define LNCP 122.93314

#define DEGTORAD (3.14159265358979323846/180.0)
#define RADTODEG (1.0/DEGTORAD)


using namespace std;

float asinDEG(float x) {
    return RADTODEG * asin(x);
}

float sinDEG(float x) {
    return sin(DEGTORAD * x);
}

float cosDEG(float x) {
    return cos(DEGTORAD * x);
}

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
        latitude = asinDEG( sinDEG(DNGP)*sinDEG(declination) + cosDEG(DNGP));
        longitude = LNCP - asinDEG( (cosDEG(declination) * sinDEG(rightAscension - ANGP)) / cosDEG(latitude));
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
