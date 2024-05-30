#include <iostream>
#include <vector>
#include "particule.h"
#include "Neon.h"
using namespace std;


   std::ostream& operator<<(std::ostream& sortie, Neon const& part) 
            { return part.affiche(sortie); }


std::ostream& Neon::affiche(std::ostream& sortie) const {
     sortie << "particule  Neon :" << " pos : " << position << ", v : " << vitesse << ", m : " << masse << endl; 
     return sortie;
    }   