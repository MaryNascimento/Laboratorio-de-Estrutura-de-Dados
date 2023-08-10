#include <iostream>

using namespace std;

int main(){
    int* Assinatura = new int[3];
    int n;

    for(int i = 0; i < 3; i++){
        cout<<"Digite um numero inteiro positivo"<<endl;
        cin>>Assinatura[i];
    }

    cout<<"Quantos Elementos tera a sequencia?"<<endl;
    cin>>n;


}