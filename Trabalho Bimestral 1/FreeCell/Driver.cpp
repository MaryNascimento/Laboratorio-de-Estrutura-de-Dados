// Nome: Mariana do Nascimento Evangelista
// Código: 2169562

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "Game.h"
#include "Game.cpp"

using namespace std;

void Init_Game(int &n){
    cout<<"Iniciar Novo Jogo?"<<endl;
    cout<<"1 - Sim"<<endl<<"2 - Nao"<<endl;

    cin>>n;

    cout<<endl;

}

int main(){
    int option;
    Init_Game(option);

    while(option == 1){
        Game new_game;
        new_game.Distribute_Cards();

        while(!new_game.End_Game()){
            new_game.Show_Game();
            new_game.Move_Card();
        }

        Init_Game(option);

    }


    
}