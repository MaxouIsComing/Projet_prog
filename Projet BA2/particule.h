#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"
#include"Enceinte.h"
#include"Systeme.h"
#include<random>
class Particule {
    protected: // ne pas oublier le destructeur!!!!
        Vecteur3D position;
        Vecteur3D vitesse;
        double masse;
        GenerateurAleatoire tirage;
    public:
 // ======================================================================================================================================
    //constructeur par défaut/ copie/ initialisation
        Particule() : position(), vitesse(), masse(0.0) {}
        Particule( Vecteur3D pos, Vecteur3D vit, double m) : position(pos), vitesse(vit), masse(m) {}
        Particule(const Particule& autre) : position(autre.position), vitesse(autre.vitesse), masse(autre.masse) {}
// ======================================================================================================================================
    // Getters
        double getPosition(int pos) const;
        double getVitesse(int pos) const ;
        double getMasse() const;
        Vecteur3D getVitesse()const;
// ======================================================================================================================================
    // Setters
        void setPosition(const Vecteur3D& pos);
        void setVitesse( Vecteur3D& vit);
        void setMasse(double m);
// ======================================================================================================================================
   //surcharge d'opérateur interne
   virtual std::ostream& affiche(std::ostream& sortie) const;
// ======================================================================================================================================
 // methode pour l'evolution du systeme
    virtual void evolue(double dt) {
        double x;
        double y;
        double z;

        x = dt*getVitesse(0);
        y = dt*getVitesse(1);
        z = dt*getVitesse(2); 
        setPosition({x,y,z});
    }

 virtual void BounceWall(const Enceinte& e) {

        double x_min = 0.0;
        double x_max = e.getLargeur();
        double y_min = 0.0;
        double y_max = e.getProfondeur();
        double z_min = 0.0;
        double z_max = e.getHauteur();

        // Vérifier si la particule a atteint ou dépassé les limites de l'enceinte sur chaque axe
        if (getPosition(0) <= x_min || getPosition(0) >= x_max) {vitesse.set_coord(0 ,-getVitesse(0));}
        if (getPosition(1) <= y_min || getPosition(1) >= y_max) {vitesse.set_coord(1 ,-getVitesse(1));}
        if (getPosition(2) <= z_min || getPosition(2) >= z_max) {vitesse.set_coord(2 ,-getVitesse(2));}
    }

bool Rencontre (const Particule& p1) {
    double EPSILON = 1;
    double distance = sqrt(  pow(p1.getPosition(0)- getPosition(0), 2) +
                            pow(p1.getPosition(1)- getPosition(1), 2) +
                            pow(p1.getPosition(2)- getPosition(2), 2));

    return distance <= EPSILON;
}
virtual void Collision(double dt) {
          
        for (int i(0) ; i<collection.size();++i){
             vector<Particule>Touche;
            Particule& p1 = *collection[i];

            for (int j(0); j<collection.size();++i) {
                Particule& p2= *collection[j];
                if (j!=i) {
                    if(p1.Rencontre(p2) ){
                        
                        Touche.push_back(p1);}
                }

            }
            if (Touche.size()==1) {
                    cout << "La particule" << collection[r] << "entre en collision avec une autre particule" << endl;
                    Touche[0].evolue(dt);
                    evolue(dt);
                }

            if(Touche.size()==2) {
                int  t =tirage.uniforme(0,2);
                cout << "La particule" << collection[t] << "entre en collision avec une autre particule" << endl;
                Touche[t].evolue(dt);
                evolue(dt);
                VitesseApresChoc(Touche[t],Touche[i]);

                }
            Touche.clear();
        }
    }

void VitesseApresChoc(const Particule& p1, const Particule& p2) 
{
    double m1 = p1.getMasse();
    double m2 = p2.getMasse();

    Vecteur3D Vg = {(m1/(m1+m2)*p1.getVitesse(0)+m2/(m1+m2)*p2.getVitesse(0)),
                    (m1/(m1+m2)*p1.getVitesse(1)+m2/(m1+m2)*p2.getVitesse(1)),
                    (m1/(m1+m2)*p1.getVitesse(2)+m2/(m1+m2)*p2.getVitesse(2))
                    };

    Vecteur3D Vo = TirageDeVo(p1,Vg);
    Vecteur3D V11=Vg+Vo;
    Vecteur3D V12 = Vg-m1/m2*Vo;
    p1.setVitesse(V11);
    p2.setVitesse(V12);
}
    

Vecteur3D TirageDeVo (const Particule& p1, Vecteur3D Vg) {

    double L = p1.getVitesse().norme(Vg);
    double z = tirage.uniforme(-L,L);
    double phi = tirage.uniforme(0,2*M_PI);
    double r = sqrt(pow(L, 2)-(z, 2));

    Vecteur3D Vo;
    return Vo = {(r*cos(phi)),(r*sin(phi)), (z)};
}    
   };
// ======================================================================================================================================
    //surcharge d'opérateur externe 
    std::ostream& operator<<(std::ostream& sortie, Particule const& part);

class Neon : public Particule {
    public:
    Neon (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule(pos, vit, m)  {}
    
    std::ostream& affiche(std::ostream& sortie)const;
};
std::ostream& operator<<(std::ostream& sortie, Neon const& part);



class Argon : public Particule {
    public:
    Argon (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule (pos,vit,m){}

     std::ostream& affiche(std::ostream& sortie) const;
};
 std::ostream& operator<<(std::ostream& sortie, Argon const& part);

 class Helium : public Particule {
    public:
    Helium (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule (pos,vit,m){}

     std::ostream& affiche(std::ostream& sortie) const;
};
 std::ostream& operator<<(std::ostream& sortie, Helium const& part);