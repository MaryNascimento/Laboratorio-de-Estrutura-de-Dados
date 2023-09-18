#include <iostream>
#include <cmath>
#include "esfera.h"

using namespace std;

void Esfera::insertRaio(double r){
    esfera_raio = r;
}

double Esfera::raio(){
    return esfera_raio;
}

double Esfera::area(){
    return 4*M_PI*pow(esfera_raio, 2);
}

double Esfera::volume(){
    return (4*M_PI*pow(esfera_raio, 3))/3;
}