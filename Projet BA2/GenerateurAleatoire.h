#pragma once
#include <iostream>
#include<random>

class GenerateurAleatoire {
         public:
    GenerateurAleatoire(unsigned int graine = std::random_device()() ) 
    : generateur(graine){}
    double gaussienne(double moyenne, double ecart_type);
    
    double uniforme(double min, double max);
        private:
    std::default_random_engine generateur ; 
    std::uniform_real_distribution<double> distribution_uniforme ;
    std::normal_distribution<double>distribution_gaussienne ;

};
