#include <iostream>

using namespace std;

int mult_digitos(int n){
    int digito, mult = 1;

    while(n > 1){
        digito = n % 10;
        mult = digito * mult;
        n = n/10;
    }

    return mult;
}

int Persistencia (int n){
    int n_digitos, persist = 0;

    if(n / 10 < 1 ){
        return 0;
    }


    while (n / 10 >= 1){
        n = mult_digitos(n);
        persist++;
    }

    return persist;
}

int main() {
    int num;
    cout<<"Digite um Numero Inteiro Positivo"<<endl;
    cin>>num;

    cout<<"A Persistencia Multiplicativa do Numero "<<num<<" e: "<<Persistencia(num)<<endl;

}