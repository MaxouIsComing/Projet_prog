#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"

class Particule {
    private:
    Vecteur3D position;
    Vecteur3D vitesse;
    double masse;
    
    public:

    //getteur
    std:: array<double,3> get_Position() const;
    double get_Vitesse(unsigned int pos) const;
    double get_Masse() {return masse;}

    //surcharge affichage
    std::ostream& affiche(std::ostream& const sortie) const;



};

//surcharge d'opérateur externe 
std::ostream& operator<<(std::ostream& sortie, Particule const& part);

