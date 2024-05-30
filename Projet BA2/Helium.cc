#include <iostream>
#include <vector>
#include "particule.h"
#include "Helium.h"
using namespace std;

     std::ostream& Helium::affiche(std::ostream& sortie) const {
     sortie << "particule  Helium : " << "pos : " << position << ", v : " << vitesse << ", m : " << masse << endl; 
     return sortie;
    }   

std::ostream& operator<<(std::ostream& sortie, Helium const& part) 
            { return part.affiche(sortie); }