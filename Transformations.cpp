#include "CelestialObject.h"

using namespace std;

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
