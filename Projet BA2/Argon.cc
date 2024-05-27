#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include "Argon.h"
using namespace std;


std::ostream& operator<<(std::ostream& sortie, Argon const& part) 
            { return part.affiche(sortie); }

  std::ostream& Argon::affiche(std::ostream& sortie) const {
     sortie << "particule  Argon : " << "pos : " << position << ", v : " << vitesse << ", m : " << masse << endl; 
     return sortie;
    }   