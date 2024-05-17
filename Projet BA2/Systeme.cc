#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include "Systeme.h"
#include"GenerateurAleatoire.h"

using namespace std;
// ======================================================================================================================================
 // methode de la fonction evolue
void Systeme::BounceWall(const Enceinte& e,  Particule* p) {

        double x_min = 0.0;
        double x_max = e.getLargeur();
        double y_min = 0.0;
        double y_max = e.getProfondeur();
        double z_min = 0.0;
        double z_max = e.getHauteur();
        int particle_face;
        int particule_index = indice(*p);
        // Vérifier si la particule a atteint ou dépassé les limites de l'enceinte sur chaque axe
        if (p->getPosition(0) <= x_min || p->getPosition(0) >= x_max) {
           p->setVitesse(0 ,-p->getVitesse(0));
           p->setPosition(0 ,-p->getPosition(0));
            cout << "La particule " << particule_index << " rebondit sur la face ";
            if (p->getPosition(0) <= x_min) {
    
                     particle_face = 1;
            }  else {
                     particle_face = 2;
                    }
            cout << particle_face << endl;
        }
        if (p->getPosition(1) <= y_min || p->getPosition(1) >= y_max) {
            p->setVitesse(1 ,-p->getVitesse(1));
            p->setPosition(1 ,-p->getPosition(1));
            cout << "La particule " << particule_index << " rebondit sur la face ";
             if (p->getPosition(1) <= y_min) {
                     particle_face = 3;
            }  else {
                     particle_face = 4;
                    }
            cout << particle_face << endl;
        }
        
        if (p->getPosition(2) <= z_min || p->getPosition(2) >= z_max) {
            p->setVitesse(2 ,-p->getVitesse(2));
            p->setPosition(2 ,-p->getPosition(2));
            cout << "La particule " << particule_index << " rebondit sur la face ";
             if (p->getPosition(2) <= z_min) {
    
                     particle_face = 5;
            }  else {
                     particle_face = 6;
                    }
            cout << particle_face << endl;
        }
        
    }
// ======================================================================================================================================
 void Systeme::Collision(double dt) {
        for (int i(0) ; i<collection.size();++i){
            vector<int>Touche; // au lieu de mettre la particule je mets plutot l'index de celle ci par soucis de maniabilité
            Particule& p1 = *collection[i];

            for (int j=i+1; j<collection.size();++j) {
                Particule& p2= *collection[j];
                if ((p1.Rencontre(p2))) {
                    Touche.push_back(j);
                }
            }
            if (!Touche.empty()){ 
                    int t = tirage.uniforme(0,Touche.size()-1);
                    int index = Touche[t];
                    Particule &p2 = *collection[index];
                    int pos = index+1;
                    cout << "La particule " << pos  << " entre en collision avec une autre particule" << endl;
                    cout << "Avant le choc :" << endl;
                    cout << "part. " << pos << " :: " ;
                    p2.Particule::affiche(cout) << endl;
                    cout << "autre :: " ;
                    p1.Particule::affiche(cout) << endl;
                    VitesseApresChoc(p2,p1);
                    cout << "Après le choc :" << endl;
                    cout << "part. " << pos << " :: "; 
                    p2.Particule::affiche(cout) << endl;
                    cout << "autre :: " ;
                    p1.Particule::affiche(cout) << endl;    
                   
            }
        Touche.clear();
        }
    }
//======================================================================================================================================
void Systeme::VitesseApresChoc( Particule& p1,  Particule& p2) {
    double m1 = p1.getMasse();
    double m2 = p2.getMasse();
    double M_TOT = m1+m2;
    Vecteur3D Vg = (m1/M_TOT)*p1.getVitesse()+(m2/M_TOT)*p2.getVitesse();
    Vecteur3D Vo = TirageDeVo(p1,Vg);
    Vecteur3D V1a=Vg+Vo;
    Vecteur3D V1b = Vg-(m1/m2)*Vo;
    p1.setVitesse(V1a);
    p2.setVitesse(V1b);
}
// ======================================================================================================================================
Vecteur3D Systeme::TirageDeVo (const Particule& p1, Vecteur3D Vg) {

    Vecteur3D inter = p1.getVitesse()-Vg;
    double L = inter.norme();
    double z = tirage.uniforme(-L,L);
    double phi = tirage.uniforme(0, 2*M_PI);
     double r = sqrt(pow(L, 2)-pow(z, 2));
    Vecteur3D Vo;
    int i =1;
    if (i ==1){ 
                phi = M_PI/3;
                ++i;
                return Vo = {(L*cos(phi)),(L*sin(phi)), (0)};
                }
    return Vo = {(r*cos(phi)),(r*sin(phi)), (z)};
} 
// ======================================================================================================================================
int Systeme::indice( Particule& p) const {
    for (size_t i = 0; i < collection.size(); ++i) {
        if (p == *collection[i]) {
            return i + 1;
        }
    }
    return 0; // Retourne 0 si la particule n'est pas trouvée (aucun indice valide)
}
// ======================================================================================================================================
void Systeme::evolue(double dt) {
     
    for (auto const& p : collection) {
        p-> evolue(dt);
        BounceWall(E,p.get());
    }
   Collision(dt);
}

// ======================================================================================================================================
  std::ostream& Systeme::affiche(std::ostream& output) const { 
        for(auto const& p : collection) {
            p->affiche(output);
        }
    return output;
    }
// ======================================================================================================================================
    void Systeme:: ajouter_particule(Particule* p){
        if(p!=nullptr) {collection.push_back(std::unique_ptr<Particule> (p)); }
    }
// ======================================================================================================================================
    void Systeme:: vider_particules(Particule* const& p){collection.clear();}


// ======================================================================================================================================
    std::ostream& operator<<(std::ostream& output, Systeme const& sys) {return sys.affiche(output);}
