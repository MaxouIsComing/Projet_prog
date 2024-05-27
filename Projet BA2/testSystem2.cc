#include <iostream>
#include <vector>
#include "Systeme.h"
#include"particule.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "Vecteur3D.h"

using namespace std;

int main() {

int taille_enceinte;
int nb_argon;
int nb_helium;
int nb_neon;


cout << "Quelle taille d'enceinte voulez vous ? " << endl;
cin >> taille_enceinte;

cout << "Quelle nombre de particules d'helium ?" << endl;
cin>>nb_helium;


cout << "Quelle nombre de particules d'argon ?" << endl;
cin>>nb_argon;


cout << "Quelle nombre de particules de neon ?" << endl;
cin>>nb_neon;
// Création d'une instance de système
Systeme systeme(taille_enceinte,taille_enceinte,taille_enceinte);

 // Création d'instances de particules
systeme.InitialiseSysteme(nb_helium,nb_neon,nb_argon); 
cout << "Le systeme est composé des "<<systeme.getTaille()<< "  particules suivantes." << endl;
cout << systeme << endl;

int i(0);
int iter;
double dt;

cout << "Combien de fois voulez vous voir votre systeme évoluer ? " << endl;
cin >> iter ;

cout <<"Avec quelle intervalle de temps ? " << endl;
cin >> dt;

cout << "Lancement de la simulation" << endl;
cout << "============-------"<<endl;



while (i < iter) {
    systeme.evolue(dt);
    cout << systeme << endl;
    cout << "============-------"<<endl;
    ++i;
    }
    return 0;
}