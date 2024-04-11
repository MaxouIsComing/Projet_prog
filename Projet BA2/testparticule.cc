#include <iostream>
#include <array>
#include <vector>
#include "particule.h"

using namespace std;

int main() {

Particule p1 ({1,1,1}, {0,0,0}, 4.002602 );

Particule p2 ({1,18.5,1}, {0,0.2,0}, 20.1797);

Particule p3 ({1,1,3.1}, {0,0,0.5}, 39.948);

Particule p4 (p2);

cout << "Particule 1 : " << p1 << endl;
cout << "Particule 2 : " << p2 << endl;
cout << "Particule 3 : " << p3 << endl;
cout << "Particule 4 : " << p4 << endl;

    return 0;
}