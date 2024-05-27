#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include "Systeme.h"
#include "Argon.h"
#include "Neon.h"
#include "Helium.h"
#include"GenerateurAleatoire.h"

using namespace std;
// ======================================================================================================================================
//fonction pour gérer les collisions avec les parois
void Systeme::BounceWall(Particule* p) { 

        const double x_min = 0.0;
        const double x_max = E.getLargeur();
        const double y_min = 0.0;
        const double y_max = E.getProfondeur();
        const double z_min = 0.0;
        const double z_max = E.getHauteur();
    // Gestion des collisions avec les parois
        GererCollision(p, 0, x_min, x_max, 3, 4); // Axe x
        GererCollision(p, 1, y_min, y_max, 2, 1); // Axe y
        GererCollision(p, 2, z_min, z_max, 6, 5); // Axe z
}
                  
//fonction auxiliaire pour eviter la duplication de code
void Systeme::GererCollision(Particule* p, int axe, double min, double max, int faceMin, int faceMax) {
    double position = p->getPosition(axe);
    if (position <= min || position >= max) {
        p->setVitesse(axe, -p->getVitesse(axe));
        int particule_index = indice(*p);
        cout << "La particule " << particule_index << " rebondit sur la face ";
        if (position <= min) {
            p->setPosition(axe, -position);
            cout << faceMin;
        } else {
            p->setPosition(axe, 2 * max - position);
            cout << faceMax;
        }
        std::cout << std::endl;
    }
}

// ======================================================================================================================================
 //fonctions qui gère les collisions entre les particules
 void Systeme::Collision(double dt) {

    vector<int> nouvellesCollisions1;
    vector<int> nouvellesCollisions2;

        for (size_t i(0) ; i<collection.size();++i){
            vector<int>Touche; // au lieu de mettre la particule je mets plutot l'index de celle ci par soucis de maniabilité
            Particule& p1 = *collection[i];
            for (int j=i+1; j<collection.size();++j) { // pas besoin de faire de double incrementation car si 1 n'a pas rencontré 2 alors 2 ne va pas rencontrer 1 d'ou j = i+1
                Particule& p2= *collection[j];
                if ((p1.Rencontre(p2))and (!collisionRecente(i,j)))  {  // Vérifier si cette paire est déjà dans les collisions récentes
                    Touche.push_back(j);
                }   
        }
            
            if (!Touche.empty()) { 
                int t = tirage.uniforme(0,Touche.size()-1);
                int index = Touche[t];
                Particule &p2 = *collection[index];
                affiche_collision(p1,p2,index); // fonction auxiliaire pour améliorer la lisibilité du code
                nouvellesCollisions1.push_back(i);
                nouvellesCollisions2.push_back(index);
            }
        Touche.clear();
        collisionIndex1 = nouvellesCollisions1;
        collisionIndex2 = nouvellesCollisions2;         
        } 
    
 }
 //fonction qui empêche deux particules qui viennent de rentrer en collision de se retoucher juste après si dt est trop court
 bool Systeme::collisionRecente(int i, int j) const {
    if ((!collisionIndex1.empty()) and (!collisionIndex2.empty())){
        for (size_t k = 0; k < collisionIndex1.size(); ++k) {
            if ((collisionIndex1[k] == i and collisionIndex2[k] == j) ||
                (collisionIndex1[k] == j and collisionIndex2[k] == i)) {
                    return true;
            }
        }   
    }
     return false;
}
//fonction auxiliaire pour l'affichage
void Systeme::affiche_collision (Particule& p1, Particule& p2, int index) {
        int pos = index+1;
        cout << "La particule " << pos  << " entre en collision avec une autre particule" << endl;
        cout << "Avant le choc :" << endl;
        cout << "part. " << pos << " :: " ;
        p2.Particule::affiche(cout) << endl; // utilisation de l'op de resolution de portée pour afficher la fonction affiche de particule et non de la sous classe.
        cout << "autre :: " ;
        p1.Particule::affiche(cout) << endl; // utilisation de l'op de resolution de portée pour afficher la fonction affiche de particule et non de la sous classe.
        VitesseApresChoc(p2,p1);
        cout << "Après le choc :" << endl; 
        cout << "part. " << pos << " :: "; 
        p2.Particule::affiche(cout) << endl; // utilisation de l'op de resolution de portée pour afficher la fonction affiche de particule et non de la sous classe.
        cout << "autre :: " ;
        p1.Particule::affiche(cout) << endl;  // utilisation de l'op de resolution de portée pour afficher la fonction affiche de particule et non de la sous classe.  
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
    if (i ==1){ //forcer le choix du premier V0
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
    return -1; // Retourne -1 si la particule n'est pas trouvée , utile au debugage
}
// ======================================================================================================================================
void Systeme::evolue(double dt) {
    
    
    for (auto const& p : collection) {
        p->evolue(dt);  
        BounceWall(p.get());         
    }
    Collision(dt);
}
// ======================================================================================================================================
void Systeme::InitialiseSysteme(int nb_helium, int nb_neon, int nb_argon) { //fonction qui initialise le système
    ajouter_particules_helium(nb_helium);
    ajouter_particules_neon(nb_neon);
    ajouter_particules_argon(nb_argon);
}

void Systeme::ajouter_particules_helium(int nb) {
    for (int i = 0; i < nb; ++i) {
        Vecteur3D position = Vecteur3D(tirage.uniforme(0.0, E.getLargeur()), 
                                       tirage.uniforme(0.0, E.getProfondeur()), 
                                       tirage.uniforme(0.0, E.getHauteur()));
        double masse = 4.0026;
        double vx = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        double vy = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        double vz = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        Vecteur3D vitesse(vx, vy, vz);
        collection.push_back(std::unique_ptr<Particule>(new Helium(position, vitesse, masse)));
    }
}

void Systeme::ajouter_particules_neon(int nb) {
    for (int i = 0; i < nb; ++i) {
        Vecteur3D position = Vecteur3D(tirage.uniforme(0.0, E.getLargeur()), 
                                       tirage.uniforme(0.0, E.getProfondeur()), 
                                       tirage.uniforme(0.0, E.getHauteur()));
        double masse = 20.1797;
        double vx = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        double vy = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        double vz = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        Vecteur3D vitesse(vx, vy, vz);
        collection.push_back(std::unique_ptr<Particule>(new Neon(position, vitesse, masse)));
    }
}

void Systeme::ajouter_particules_argon(int nb) {
    for (int i = 0; i < nb; ++i) {
        Vecteur3D position = Vecteur3D(tirage.uniforme(0.0, E.getLargeur()), 
                                       tirage.uniforme(0.0, E.getProfondeur()), 
                                       tirage.uniforme(0.0, E.getHauteur()));
        double masse = 39.948;
        double vx = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        double vy = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        double vz = tirage.gaussienne(0.0, sqrt(1000 * R / masse * temperature)/1000);
        Vecteur3D vitesse(vx, vy, vz);
        collection.push_back(std::unique_ptr<Particule>(new Argon(position, vitesse, masse)));
    }
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
        if(p!=nullptr) {    collection.push_back(std::unique_ptr<Particule> (p)); }
     }
// ======================================================================================================================================
    void Systeme:: vider_particules(Particule* const& p){collection.clear();}
// ======================================================================================================================================
    std::ostream& operator<<(std::ostream& output, Systeme const& sys) {return sys.affiche(output);}
// ======================================================================================================================================
    int Systeme::getTaille() const{ return collection.size();}
