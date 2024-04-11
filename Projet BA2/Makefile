CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  -pedantic -Wall         

all: testVecteur3D  testparticule

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

particule.o: particule.cc particule.h Vecteur3D.h

testparticule.o : testparticule.cc particule.h Vecteur3D.h

testparticule : testparticule.o particule.o


