#include <iostream>
#include "esfera.h"

using namespace std;

int main(){
    Esfera minha_esfera;

    minha_esfera.insertRaio(1.73);

    cout<<"Raio: "<< minha_esfera.raio()<<endl;
    cout<<"Area: "<< minha_esfera.area()<<endl;
    cout<<"Volume: "<<minha_esfera.volume()<<endl;


}