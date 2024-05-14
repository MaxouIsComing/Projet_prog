#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include "Systeme.h"

using namespace std;
// ======================================================================================================================================
 // methode de la fonction evolue
void Systeme::BounceWall(const Enceinte& e,  Particule *p) {

        double x_min = 0.0;
        double x_max = e.getLargeur();
        double y_min = 0.0;
        double y_max = e.getProfondeur();
        double z_min = 0.0;
        double z_max = e.getHauteur();

        // Vérifier si la particule a atteint ou dépassé les limites de l'enceinte sur chaque axe
        if (p->getPosition(0) <= x_min || p->getPosition(0) >= x_max) {p->getVitesse().set_coord(0 ,-p->getVitesse(0));}
        if (p->getPosition(1) <= y_min || p->getPosition(1) >= y_max) {p->getVitesse().set_coord(1 ,-p->getVitesse(1));}
        if (p->getPosition(2) <= z_min || p->getPosition(2) >= z_max) {p->getVitesse().set_coord(2 ,-p->getVitesse(2));}
    }

 void Systeme::Collision(double dt) {
          
        for (int i(0) ; i<collection.size();++i){
             vector<Particule>Touche;
            Particule& p1 = *collection[i];

            for (int j(0); j<collection.size();++i) {
                Particule& p2= *collection[j];
                if (j!=i) {
                    if(p1.Rencontre(p2) ) 
                        {Touche.push_back(p1);}
                }

            }
            if (Touche.size()==1) {
                    cout << "La particule" << p1 << "entre en collision avec une autre particule" << endl;
                    cout << "Avant le choc : " << endl;
                    cout << "part. " << i << " :: " << p1 << endl;
                    cout << "autre :: " << Touche[1] << endl;
                    VitesseApresChoc(Touche[1],Touche[i],dt);
                    cout << "Après le choc :" << endl;
                    cout << "part. " << i << " :: " << p1 << endl;
                    cout << "autre :: " << Touche[1] << endl;
                }

            if(Touche.size()==2) {
                    int  t =tirage.uniforme(0,2);
                    cout << "La particule" << p1 << "entre en collision avec une autre particule" << endl;
                    cout << "Avant le choc :" << endl;
                     cout << "part. " << i << " :: " << p1 << endl;
                    cout << "autre :: " << Touche[t] << endl;
                    VitesseApresChoc(Touche[t],Touche[i],dt);
                    cout << "Après le choc :" << endl;
                    cout << "part. " << i << " :: " << p1 << endl;
                    cout << "autre :: " << Touche[t] << endl;
                }
            Touche.clear();
        }
    }

void Systeme::VitesseApresChoc( Particule& p1,  Particule& p2, double dt) {
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
    p1.evolue(dt);
    p2.evolue(dt);
}
Vecteur3D Systeme::TirageDeVo (const Particule& p1, Vecteur3D Vg) {

    double L = p1.getVitesse().norme(Vg);
    double z = tirage.uniforme(-L,L);
    double phi = tirage.uniforme(0,2*M_PI);
    double r = sqrt(pow(L, 2)-(z, 2));

    Vecteur3D Vo;
    return Vo = {(r*cos(phi)),(r*sin(phi)), (z)};
} 
void Systeme::evolue(double dt) {
    for (auto& p : collection) {
        p->evolue(dt);
        BounceWall(E,*p);
    }

    Collision(dt);
}

// ======================================================================================================================================
  std::ostream& Systeme::affiche(std::ostream& output) const { 
    cout << "Le système est composé de " << collection.size() << " particules " << endl;
        for(auto const& p : collection) {
            p->affiche(output);
        }
    }
// ======================================================================================================================================
    void Systeme:: ajouter_particule(Particule* const& p){
        if(p!=nullptr) {collection.push_back(unique_ptr<Particule>(p)); }
    }
// ======================================================================================================================================
    void Systeme:: vider_particules(Particule* const& p){collection.clear();}
// ======================================================================================================================================
    std::ostream& operator<<(std::ostream& output, Systeme const& sys) {return sys.affiche(output);}
