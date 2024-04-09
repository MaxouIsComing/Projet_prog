CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  -pedantic -Wall         

all: testVecteur3D Vecteur3D

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

particule.o: particule.cc particule.h
