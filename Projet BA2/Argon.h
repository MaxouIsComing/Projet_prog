#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"
#include "particule.h"



class Argon : public Particule {
    public:
    Argon (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule (pos,vit,m){}

     std::ostream& affiche(std::ostream& sortie) const;
};
 std::ostream& operator<<(std::ostream& sortie, Argon const& part);