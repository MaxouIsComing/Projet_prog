#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "particule.h"


class Neon : public Particule {
    public:
    Neon (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule(pos, vit, m)  {}
    
    std::ostream& affiche(std::ostream& sortie)const;
};
std::ostream& operator<<(std::ostream& sortie, Neon const& part);