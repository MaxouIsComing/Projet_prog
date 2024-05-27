#pragma once
#include <iostream>
#include "Vecteur3D.h"
#include "Enceinte.h"
#include"GenerateurAleatoire.h"

class Particule;

class Systeme {
    private:
    std::vector<std::unique_ptr<Particule>> collection;
    Enceinte E;
    GenerateurAleatoire tirage=123456;
    const double R = 8.314472;
    const double temperature = 293.15;
    std::vector<int> collisionIndex1;
    std::vector<int> collisionIndex2;

// ======================================================================================================================================
    //constructeur par défaut/ initialisation
    public:
    Systeme () 
        :  collection(), E()    {} 

    Systeme ( double Hauteur, double Profondeur, double Largeur)
    : collection(), E(Hauteur,Profondeur,Largeur)
    {}
// ======================================================================================================================================
    //surcharge affichage interne 
    std::ostream& affiche(std::ostream& output) const;

// ======================================================================================================================================
//ajout,suppression de particule
    void ajouter_particule(Particule*  p);
    void vider_particules(Particule* const& p);
    Systeme(Systeme const&) = delete; 
    Systeme operator=(Systeme const&) = delete; 
// ======================================================================================================================================
 // methode pour l'evolution du systeme
    void BounceWall(Particule* p);
    virtual void Collision(double dt);
    bool collisionRecente(int i, int j) const;
    void VitesseApresChoc( Particule& p1,  Particule& p2);
    Vecteur3D TirageDeVo (const Particule& p1, Vecteur3D Vg);
    int indice( Particule& p) const ;
    void evolue(double dt);
    void InitialiseSysteme (int nb_helium, int nb_neon, int nb_argon);
    void ajouter_particules_helium(int nb);
    void ajouter_particules_neon(int nb);
    void ajouter_particules_argon(int nb);
    void affiche_collision (Particule& p1, Particule& p2, int index);
    void GererCollision(Particule* p, int axis, double min, double max, int faceMin, int faceMax);
    int getTaille() const; 
};

// ======================================================================================================================================
//surcharge affichage externe 
std::ostream& operator<<(std::ostream& output, Systeme const& sys);








    






