#ifndef GAME_H
#define GAME_H

#include <iostream>

using namespace std;


class Game{
    private:

        struct Card{
            int value;
            char suit;
            char color;
            char symbol[6];
        };

        struct Stack{
            Card stack[27];
            char suit;
            int top;
        };

        Card deck_game[52];
        Stack stack_game[8];
        Stack stack_exit[4];
        Card free_cells[4];
        bool check;

        void Deck_Start(); //Inicia as cartas do baralho, com valor, naipe, cor e símbolo
        bool Full_StackExit(int i); //Retorna true se a pilha de saída estiver cheia
        bool Full_StackGame(int n); //Retorna true se a pilha de jogo possuir mais de 26 cartas
        bool Empty_StackExit(int i); //Retorna true se a pilha de saída estiver vazia
        bool Empty_StackGame(int n); //Retorna true se a pilha de jogo estiver vazia
        bool Empty_Freecells(int n); //Retorna true se as free cells estiverem vazias
        void Top_StackExit(Card &x, int i); //Retorna o elemento no topo em uma das pilhas de saída
        void Top_StackGame(int n, Card &x); //Retorna o elemento no topo em uma das pilhas de jogo
        void Push(int n, Card x); //Adiciona uma carta na pilha de jogo n
        void Pop(int n, Card &x); //Retira uma carta da pilha de jogo n
        void Shuffle_Deck(); //Embaralha as cartas de forma aleatória
        bool No_Move(Card x, int n); //Verifica se uma carta x pode ser movimentada

    public:

        Game();
        
        void Distribute_Cards(); //Distribui as cartas embaralhadas para as pilhas de jogo
        void Show_Game(); //Imprime o conteúdo das pilhas
        void Move_Card(); //Move as cartas entre as pilhas
        bool End_Game(); //Sinaliza se o jogo terminou
    
};
#endif