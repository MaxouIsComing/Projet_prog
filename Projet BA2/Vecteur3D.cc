#include <vector>
#include <iostream>
#include <cmath>
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

    Vecteur3D addition (Vecteur3D autre) const {
        Vecteur3D resultat;
         for (size_t i(0); i < 3 ; ++i){ resultat.coord[i] =coord[i] + autre.coord[i];}
         return resultat;
    }

    Vecteur3D mult(double scalaire) const {
        Vecteur3D resultat;
        for (size_t i (0); i < 3; ++i) {resultat.coord[i] = scalaire*coord[i];}
        return resultat;
    }

    Vecteur3D opposee () const {
        Vecteur3D resultat;
        resultat.coord = coord;
        return resultat.mult(-1);
        }

    Vecteur3D soustraction (Vecteur3D autre) const {
        Vecteur3D resultat;
        resultat.coord = coord;
        autre = autre.opposee();
        resultat = resultat.addition(autre);
        return resultat;
    }

    double prod_scal(Vecteur3D autre) const {
        Vecteur3D resultat;
        double prod_scalaire(0.0);
        for (size_t i (0); i < 3; ++i) { prod_scalaire += resultat.coord[i]*autre.coord[i];}
        return prod_scalaire;
    }
    Vecteur3D prod_vect(Vecteur3D autre) const {
        Vecteur3D resultat;
        for (size_t i(0) ; i < 3 ; ++i) {
            resultat.coord[i] = coord[(i+1)%3]*autre.coord[(i+2)%3] - coord[(i+2)%3]*autre.coord[(i+1)%3];
            } 
        return resultat;
    }

    double norme2(Vecteur3D autre) const {
        double norme2(0.0);
        for (size_t i(0); i < 3 ; ++i) {
            norme2 += autre.coord[i]*autre.coord[i];
        }
        return norme2;
    }
  double norme(Vecteur3D autre) {return sqrt(norme2(autre));}

  Vecteur3D unitaire () {
    Vecteur3D unitaire;
    unitaire.coord = coord;
    double norme_vect = norme(unitaire);
    unitaire = unitaire.mult(1/norme_vect);
    return unitaire ;
  }


private :
     array <double, 3> coord ;
};

int main () {

Vecteur3D vect1;
Vecteur3D vect2;
Vecteur3D vect3;


/* Cette partie sera revue dans 2 semaines
 * (constructeurs, surcharge des opérateurs).
 */
// v1 = (1.0, 2.0, -0.1)
vect1.set_coord(0, 1.0);
vect1.set_coord(1, 2.0);
vect1.set_coord(2, -0.1);

// v2 = (2.6, 3.5,  4.1)
vect2.set_coord(0, 2.6);
vect2.set_coord(1, 3.5);
vect2.set_coord(2, 4.1);

Vecteur3D vect4;
vect4.set_coord(0,3);
vect4.set_coord(2,5);
vect4.set_coord(1,4);

Vecteur3D vect5;
vect5.set_coord(0,0);
vect5.set_coord(2,0);
vect5.set_coord(1,0);

cout << "Vecteur 1 : ";
vect1.affiche();
cout << endl;

cout << "Vecteur 2 : ";
vect2.affiche();
cout << endl;
 
vect3 = vect1;

cout << "Le vecteur 1 est ";
if (vect1.compare(vect2)) {
    cout << "égal au";
} else {
    cout << "different du";
}
cout << " vecteur 2," << endl << "et est ";
if (not vect1.compare(vect3)) {
    cout << "different du";
} else {
    cout << "egal au";
}
cout << " vecteur 3." << endl;

vect1 = vect2.soustraction(vect1);
vect1.affiche();

vect1 = vect1.opposee();
vect1.affiche();

vect4 = vect4.unitaire();
vect4.affiche();

vect5 = vect5.unitaire();
vect5.affiche();

    return 0;
}





