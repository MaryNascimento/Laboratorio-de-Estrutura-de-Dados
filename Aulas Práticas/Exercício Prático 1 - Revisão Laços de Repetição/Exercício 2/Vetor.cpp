#include <iostream>

using namespace std;

int main(){
    int vetor[13] = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    int contador = 0, n_impar;

    for (int i = 0; i < 13; i++){
        for ( int j = 0; j <13; j++){
            if(vetor[i] == vetor[j]){
                contador++;
            }
        }

        if (contador%2 != 0){
            n_impar = vetor[i];
        }

        contador = 0;
    }

    cout<<"O inteiro que aparece um numero impar de vezes e "<<n_impar<<endl;
}