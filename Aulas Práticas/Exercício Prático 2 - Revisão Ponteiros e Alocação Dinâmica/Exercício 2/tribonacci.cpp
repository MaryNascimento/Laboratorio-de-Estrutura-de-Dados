#include <iostream>

using namespace std;

void tribonacci (int* Sequencia, int n){
    int ultimo, penult, antipenult;

    n = n+3;
    Sequencia = new int[n];

    cout<<"Preencha os 3 digitos da Assinatura"<<endl;
    for(int i = 0; i < 3; i++){
        cin>>Sequencia[i];
    }

    cout<<"===== Assinatura ====="<<endl;
    for(int i = 0; i < 3; i++){
        cout<<Sequencia[i]<<" ";
    }

    cout<<endl;

    cout<<"===== Sequencia de Tribonacci ====="<<endl;

    for (int i = 0; i < n; i++){
        antipenult = Sequencia[i];
        penult = Sequencia[i + 1];
        ultimo = Sequencia[i + 2];
        Sequencia[i + 3] = antipenult + penult + ultimo;

        cout<<Sequencia[i]<<" ";
    }

}

int main(){
    int* Sequencia;
    unsigned int n;

    cout<<"Quantos Elementos deseja calcular?"<<endl;
    cin>>n;

    if(n == 0){
        cout<<"[ ]"<<endl;
    } else {
        tribonacci(Sequencia, n);
    }

}