CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  -pedantic -Wall         

all: testSystem1 testparticule testVecteur3D testSystem2

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

particule.o: particule.cc particule.h Vecteur3D.h

testparticule.o : testparticule.cc particule.h Vecteur3D.h

testparticule : testparticule.o particule.o Vecteur3D.o

GenerateurAleatoire.o :GenerateurAleatoire.cc GenerateurAleatoire.h

systeme.o : systeme.cc systeme.h Vecteur3D.h particule.h GenerateurAleatoire.h Helium.h Argon.h Neon.h

Helium.o : Helium.cc Helium.h particule.h Vecteur3D.h

Argon.o : Argon.cc Argon.h particule.h Vecteur3D.h

Neon.o : Neon.cc Neon.h particule.h Vecteur3D.h

testSystem1 :  testSystem1.o systeme.o Vecteur3D.o particule.o GenerateurAleatoire.o Neon.o Argon.o Helium.o

testSystem1.o : testSystem1.cc Vecteur3D.h particule.h GenerateurAleatoire.h Helium.h Argon.h Neon.h

testSystem2 : testSystem2.o systeme.o Vecteur3D.o particule.o GenerateurAleatoire.o Neon.o Argon.o Helium.o

testSystem2.o : testSystem2.cc Vecteur3D.h particule.h GenerateurAleatoire.h Helium.h Argon.h Neon.h

