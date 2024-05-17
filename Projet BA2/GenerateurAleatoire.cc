#include <iostream>
#include "GenerateurAleatoire.h"
using namespace std;


double GenerateurAleatoire::uniforme(double min, double max) 
    { return distribution_uniforme(generateur, std::uniform_real_distribution<double>::param_type{min,max});}