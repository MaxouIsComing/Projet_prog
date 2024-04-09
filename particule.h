#include <iostream>
#include <array>
#include <vector>
#include <cmath>

class Particule {
    private:
    std::array <double,3>position;
    double vitesse;
    double masse;
    
    public:

    //getteur
    std:: array<double,3> get_Position() {return position;}
    double get_Vitesse() {return vitesse;}
    double get_Masse() {return masse;}

    //surcharge affichage
    std::ostream& affiche(std::ostream& const sortie);



};
// surcharge d'opérateur externe
//surcharge d'opérateur externe 
std::ostream& operator<<(std::ostream& sortie, Particule const& part);

