#include "CelestialObject.h"

using namespace std;

int main(){
    CelestialObject test1("Bob", 1.0, 2.0, 3.5, 2.9, 17.1);
    CelestialObject test2(2.3, 1.79, 17467178.18418, 16.1, 23.0);
    test1.print();
    test2.print();
    return 1;
}