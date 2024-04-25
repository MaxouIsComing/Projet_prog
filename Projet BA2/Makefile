CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  -pedantic -Wall         

all: testVecteur3D  testparticule testSystem1

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

particule.o: particule.cc particule.h Vecteur3D.h

testparticule.o : testparticule.cc particule.h Vecteur3D.h

testparticule : testparticule.o particule.o Vecteur3D.o

systeme.o : systeme.cc systeme.h Vecteur3D.h particule.h

testSystem1 :  testSystem1.o systeme.o Vecteur3D.o particule.o 

testSystem1.o : testSystem1.cc Vecteur3D.h particule.h 


