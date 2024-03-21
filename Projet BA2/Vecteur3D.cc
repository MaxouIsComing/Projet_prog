#include <vector>
#include <iostream>
#include <cmath>
#include <array>

using namespace std;


class Vecteur3D {

public :

    void set_coord(int pos, double new_coord) {
        if ((pos >= 0) and (pos < 3)) {  coord[pos] = new_coord; }
        else {  cout << "Coordonnée n'existe pas" << endl;  }
     }

    void affiche () const { cout << coord[0] << " " << coord[1] << " " << coord[2] << endl; }

    bool compare (Vecteur3D vect) { 
        const double epsilon = exp(-10);
        for (size_t i(0); i < 3 ; ++i) {
            if (abs(coord[i]- vect.coord[i])>epsilon) {return false;}    
        }     
        return true;
    }
bool  Vecteur3D::operator==(Vecteur3D autre) const 
  {
    for (size_t i(0) ; i < coord.size() ; ++i)
    {
      if (abs(coord[i] - autre.coord[i]) > 1e-10) {return false;}
    }
    return true;
  }
// ==================================================================================================================================
//surcharge d'opérateurs : addition, soustraction
Vecteur3D Vecteur3D:: operator += (Vecteur3D autre)  {
        for (size_t i(0); i < 3 ; ++i){ coord[i] += autre.coord[i];}
        return *this;
    }
Vecteur3D Vecteur3D::operator -= (Vecteur3D autre)  {
        for (size_t i(0); i < 3 ; ++i){ coord[i] -= autre.coord[i];}
        return *this;
}

Vecteur3D Vecteur3D::operator +(Vecteur3D autre)  {
        Vecteur3D res(*this);
        return res+= autre;
    }

Vecteur3D Vecteur3D::operator-(Vecteur3D autre)  {
        Vecteur3D res(*this);
        return res -= autre;
    }
// ==================================================================================================================================
//surcharge d'opérateur pour la multiplication par un scalaire, et l'inverse

Vecteur3D  Vecteur3D::operator*=(double scalaire)  {
    for (size_t i (0); i < 3; ++i) {coord[i] *= scalaire;} 
    return *this;   
}

Vecteur3D operator*(Vecteur3D const& v1, double x) { 
    Vecteur3D res(v1);
    return res *= x;
}
Vecteur3D operator*(double x, Vecteur3D const& v1) { 
    Vecteur3D res(v1);
    return res *=x;
}
Vecteur3D  Vecteur3D::operator- ()  {
    Vecteur3D oppose;
    return oppose*=(-1);
    }
// ==================================================================================================================================
//surcharge d'opérateur produit scalaire/vectoriel

double Vecteur3D::operator*=(Vecteur3D autre)  {
    double prod_scalaire(0.0);
    for (size_t i (0); i < 3; ++i) { prod_scalaire += coord[i]*autre.coord[i];}
    return prod_scalaire;
    }
double Vecteur3D::operator*(Vecteur3D autre)  {
    Vecteur3D vect(*this);
    return vect *= autre;
}

Vecteur3D Vecteur3D::operator^=(Vecteur3D autre)  {
    Vecteur3D resultat;
    for (size_t i(0) ; i < 3 ; ++i) 
        {resultat.coord[i] = coord[(i+1)%3]*autre.coord[(i+2)%3] - coord[(i+2)%3]*autre.coord[(i+1)%3];} 
    return resultat;
}

Vecteur3D Vecteur3D::operator^(Vecteur3D autre)  {

    Vecteur3D vect(*this);
    return vect *= autre;
}

Vecteur3D Vecteur3D::operator~()  {
    Vecteur3D unitaire;
    unitaire.coord = coord;
    double norme_vect = norme(unitaire);
    unitaire *= (1/norme_vect);
    return unitaire ;
}
// ==================================================================================================================================
// norme euclidienne et son carré 

double Vecteur3D:: norme2(Vecteur3D autre) const {
    double norme2(0.0);
        for (size_t i(0); i < 3 ; ++i) {norme2 += autre.coord[i]*autre.coord[i];}
    return norme2;
    }
   
double Vecteur3D::norme (Vecteur3D autre) {return sqrt(norme2(autre));}
