#pragma once
#include <vector>
#include <array>
#include <cmath>
#include <iostream>


   //coucou maximus
//suce pute
class Vecteur3D {

private :
    std::array <double, 3> coord;

public :

//constructeur de copie, par defaut, initialisation
   Vecteur3D (double x = 0., double y = 0.,double z = 0.) {
        coord[0] = x;
        coord[1] = y;
        coord[2] = z;
    }

	Vecteur3D (Vecteur3D const& autre)
		: coord(autre.coord) {} 
        
// ======================================================================================================================================
// setteur 
    void set_coord(int pos, double new_coord) ;
//getteur
    double get_coord(int numero) const ;
// ======================================================================================================================================
// surcharge d'opérateurs
    bool operator ==(Vecteur3D autre) const;
    bool operator!=(Vecteur3D vect) const;
    Vecteur3D operator+=(Vecteur3D autre) ;
    Vecteur3D operator+(Vecteur3D autre) ;
    Vecteur3D operator-=(Vecteur3D autre) ;
    Vecteur3D operator-(Vecteur3D autre) ;
    Vecteur3D operator*=(double scalaire) ;
    Vecteur3D operator*(double scalaire);
    Vecteur3D operator-();
    std::ostream& affiche(std::ostream& sortie) const;
    double operator*=(Vecteur3D autre) ;
    double operator*(Vecteur3D autre) ;
    double prod_vect(Vecteur3D autre) ;
    Vecteur3D operator^=(Vecteur3D autre) ;
    Vecteur3D operator^(Vecteur3D autre) ;
    Vecteur3D operator~();

// ======================================================================================================================================
//norme et norme euclidienne
    double norme2(Vecteur3D autre) const;
    double norme(Vecteur3D autre) ;
};
// ======================================================================================================================================
//surcharge d'opérateur externe 

    std::ostream& operator<<(std::ostream& sortie, Vecteur3D const& vect);
    Vecteur3D operator*(double scalaire, Vecteur3D autre);
