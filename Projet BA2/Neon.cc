#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include "Neon.h"
using namespace std;


   std::ostream& operator<<(std::ostream& sortie, Neon const& part) 
            { return part.affiche(sortie); }


std::ostream& Neon::affiche(std::ostream& sortie) const {
     sortie << "particule  Neon :" << "position : " << position << ", vitesse : " << vitesse << ", masse : " << masse << endl; 
     return sortie;
    }   