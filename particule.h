#include <iostream>
#include <array>
#include <vector>
#include <cmath>

class Particule {
    private:
    std::array <double,3>position;
    double vitesse;
    double mass;

};
// surcharge d'opérateur externe
//surcharge d'opérateur externe 
std::ostream& operator<<(std::ostream& sortie, Particule const& part);