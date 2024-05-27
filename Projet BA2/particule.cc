#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include <cmath>
using namespace std;


// ======================================================================================================================================
    // Getters
        double Particule::getPosition(int pos) const { return position.get_coord(pos); }
        double Particule::getVitesse(int pos) const { return vitesse.get_coord(pos); }
        double Particule::getMasse() const  { return masse; }
        Vecteur3D Particule::getVitesse() const {return vitesse;}
        Vecteur3D Particule::getPosition() const {return position;}

// ======================================================================================================================================
    // Setters
        void Particule::setPosition(const Vecteur3D& pos) { position = pos; }
        void Particule::setVitesse(Vecteur3D& vit) { vitesse = vit; }
        void Particule::setMasse(double m) { masse = m; }
        void Particule::setVitesse(int pos, double new_vit) { vitesse.set_coord(pos,new_vit);}
        void Particule::setPosition(int pos, double new_pos) { position.set_coord(pos,new_pos);}


         bool Particule::operator==(const Particule& other) const {
        return (position == other.position) && (vitesse == other.vitesse) && (masse == other.masse);
    }
// ======================================================================================================================================
    //methodes evolue

     void Particule::evolue(double dt) {
            Vecteur3D deplacement = vitesse*dt;
            position = position + deplacement;
    }
    bool Particule::Rencontre (const Particule& p1) {
        Vecteur3D cg = position - p1.position;
        double distance =  cg.norme();
        return distance < EPSILON;
}
// ======================================================================================================================================
 //surcharge affichage
   std::ostream& Particule::affiche(std::ostream& sortie) const {
     sortie << "pos : " << position << ", v : " << vitesse  << endl; 
     return sortie;
    }   
    std::ostream& operator<<(std::ostream& sortie, Particule const& part) 
            { return part.affiche(sortie); }

    

 

    

        

