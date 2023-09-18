// Nome: Mariana do Nascimento Evangelista
// Código: 2169562

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "Game.h"

using namespace std;

void Game::Deck_Start()
{

    int x = 1;

    for (int i = 0; i < 52; i++)
    {

        if (x <= 13)
        {
            deck_game[i].value = x;
            x++;
        }
        else
        {
            x = 1;
            deck_game[i].value = x;
            x++;
        }

        if (i < 13)
        {
            deck_game[i].suit = 'E';
            deck_game[i].color = 'b';
        }
        else if (i < 26)
        {
            deck_game[i].suit = 'P';
            deck_game[i].color = 'b';
        }
        else if (i < 39)
        {
            deck_game[i].suit = 'U';
            deck_game[i].color = 'r';
        }
        else
        {
            deck_game[i].suit = 'C';
            deck_game[i].color = 'r';
        }

        switch (deck_game[i].value)
        {
        case 1:
            sprintf(deck_game[i].symbol, "[ A%c]", deck_game[i].suit);
            break;

        case 10:
            sprintf(deck_game[i].symbol, "[10%c]", deck_game[i].suit);
            break;

        case 11:
            sprintf(deck_game[i].symbol, "[ J%c]", deck_game[i].suit);
            break;

        case 12:
            sprintf(deck_game[i].symbol, "[ Q%c]", deck_game[i].suit);
            break;

        case 13:
            sprintf(deck_game[i].symbol, "[ K%c]", deck_game[i].suit);
            break;

        default:
            sprintf(deck_game[i].symbol, "[ %d%c]", deck_game[i].value, deck_game[i].suit);
            break;
        }
    }
}

Game::Game()
{

    Deck_Start();

    for (int i = 0; i < 4; i++)
    {
        stack_exit[i].top = 0;

        switch (i)
        {
        case 0:
            stack_exit[i].suit = 'C';
            break;

        case 1:
            stack_exit[i].suit = 'P';
            break;

        case 2:
            stack_exit[i].suit = 'U';
            break;

        case 3:
            stack_exit[i].suit = 'E';
            break;
        }

        sprintf(stack_exit[i].stack[0].symbol, "[  %c]", stack_exit[i].suit);

        free_cells[i].value = 0;
    }

    for (int i = 0; i < 8; i++)
    {
        stack_game[i].top = 0;

        for (int j = 0; j < 27; j++)
        {
            stack_game[i].stack[j].value = 0;
        }
    }
}

bool Game::Full_StackExit(int i)
{
    return stack_exit[i].top == 13;
}

bool Game::Full_StackGame(int n)
{
    return stack_game[n - 1].top == 26;
}

bool Game::Empty_StackExit(int i)
{
    return stack_exit[i].top == 0;
}

bool Game::Empty_StackGame(int n)
{
    return stack_game[n - 1].top == 0;
}

bool Game::Empty_Freecells(int n)
{
    return free_cells[n - 9].value == 0;
}

void Game::Top_StackExit(Card &x, int i)
{
    int top;
    top = stack_exit[i].top;
    x = stack_exit[i].stack[top];
}

void Game::Top_StackGame(int n, Card &x)
{
    int top;
    top = stack_game[n - 1].top;
    x = stack_game[n - 1].stack[top];
}

void Game::Push(int n, Card x)
{
    int top;
    Card k;
    if (n == 0)
    {

        for (int i = 0; i < 4; i++)
        {
            if (stack_exit[i].suit == x.suit)
            {

                Top_StackExit(k, i);

                if (Full_StackExit(i))
                {
                    check = false;
                    cout << "       A pilha esta cheia, movimento invalido      " << endl;
                }
                else if (Empty_StackExit(i) & x.value == 1)
                {
                    check = true;
                    stack_exit[i].top++;
                    top = stack_exit[i].top;
                    stack_exit[i].stack[top] = x;
                }
                else if (k.value + 1 == x.value)
                {
                    check = true;
                    stack_exit[i].top++;
                    top = stack_exit[i].top;
                    stack_exit[i].stack[top] = x;
                }
                else
                {
                    check = false;
                    cout << "                 Movimento invalido                " << endl;
                }
            }
        }
    }
    else if (n < 9)
    {

        Top_StackGame(n, k);

        if (Full_StackGame(n))
        {
            check = false;
            cout << "       A pilha esta cheia, movimento invalido      " << endl;
        }
        else if (Empty_StackGame(n))
        {
            check = true;
            stack_game[n - 1].top++;
            top = stack_game[n - 1].top;
            stack_game[n - 1].stack[top] = x;
        }
        else if (x.value + 1 == k.value & x.color != k.color)
        {
            check = true;
            stack_game[n - 1].top++;
            top = stack_game[n - 1].top;
            stack_game[n - 1].stack[top] = x;
        }
        else
        {
            check = false;
            cout << "                 Movimento invalido                " << endl;
        }
    }
    else if (n < 13)
    {

        if (Empty_Freecells(n))
        {
            check = true;
            free_cells[n - 9] = x;
            return;
        }
        check = false;
        cout << "     A celula esta ocupada, movimento invalido     " << endl;
    }
    else
    {
        check = false;
        cout << "                 Movimento invalido                " << endl;
    }
}

void Game::Pop(int n, Card &x)
{
    int top;

    if (n == 0 || n > 12)
    {
        cout << "                 Movimento invalido                " << endl;
        check = false;
    }
    else if (n < 9)
    {

        if (Empty_StackGame(n))
        {
            cout << "       A pilha esta vazia, movimento invalido      " << endl;
            check = false;
            return;
        }
        top = stack_game[n - 1].top;
        x = stack_game[n - 1].stack[top];
        stack_game[n - 1].stack[top].value = 0;
        stack_game[n - 1].top--;
        check = true;
    }
    else
    {

        if (Empty_Freecells(n))
        {
            cout << "      A celula esta vazia, movimento invalido      " << endl;
            check = false;
            return;
        }
        x = free_cells[n - 9];
        free_cells[n - 9].value = 0;
        check = true;
    }
}

void Game::Shuffle_Deck()
{
    int n;

    srand(time(0));

    for (int i = 0; i < 52; i++)
    {
        n = rand() % 52;

        swap(deck_game[i], deck_game[n]);
    }
}

void Game::Distribute_Cards()
{
    int top, p = 0;

    Shuffle_Deck();

    for (int i = 0; i < 8; i++)
    {

        if (i < 4)
        {

            for (int j = p; j < (p + 7); j++)
            {
                stack_game[i].top++;
                top = stack_game[i].top;
                stack_game[i].stack[top] = deck_game[j];
            }

            p = p + 7;
        }
        else
        {

            for (int j = p; j < (p + 6); j++)
            {

                stack_game[i].top++;
                top = stack_game[i].top;
                stack_game[i].stack[top] = deck_game[j];
            }

            p = p + 6;
        }
    }
}

void Game::Show_Game()
{
    int top;

    for (int i = 0; i < 4; i++)
    {

        if (free_cells[i].value == 0)
        {
            sprintf(free_cells[i].symbol, "[   ]");
        }

        cout << free_cells[i].symbol << " ";
    }

    cout << "      ";

    for (int i = 0; i < 4; i++)
    {

        top = stack_exit[i].top;

        cout << stack_exit[i].stack[top].symbol << " ";
    }

    cout << endl;
    cout << "  9     10    11    12          0     0     0     0" << endl<< endl;


    top = stack_game[0].top;

    for(int i = 0; i < 8; i++){
        if(stack_game[i].top > top){
            top = stack_game[i].top;
        }
    }

    for (int i = 1; i < top + 1; i++)
    {

        for (int j = 0; j < 8; j++)
        {   
            if(stack_game[j].stack[i].value > 0){
                cout<< stack_game[j].stack[i].symbol<<" ";
            } else{
                cout<<"     "<<" ";
            }  

        }

        cout<<endl;

    }

    cout << "  1     2     3     4     5     6     7     8" << endl;
}

void Game::Move_Card()
{
    int n1, n2, top;
    Card x;

    cout<<"From: ";
    cin>>n1;
    cout<<"To: ";
    cin>>n2;

    cout<<endl<<"---------------------------------------------------"<<endl;

    Pop(n1, x);

    if(check == 0){
        cout<<"---------------------------------------------------"<<endl<<endl;
        return;
    }

    Push(n2, x);

    if(check == 0){

        if(n1 < 9){
            stack_game[n1 - 1].top++;
            top = stack_game[n1 - 1].top;
            stack_game[n1 - 1].stack[top] = x;
        } else {
            free_cells[n1 - 9] = x;
        }
        cout<<"---------------------------------------------------"<<endl<<endl;
    }

    
    
    cout<<endl<<endl;

}

bool Game::No_Move(Card x, int n){
    int top;
    Card k;


    if (n == 0)
    {

        for (int i = 0; i < 4; i++)
        {
            if (stack_exit[i].suit == x.suit)
            {

                Top_StackExit(k, i);

                if (Full_StackExit(i))
                {
                    check = false;
                }
                else if (Empty_StackExit(i) & x.value == 1)
                {
                    check = true;
                }
                else if (k.value + 1 == x.value)
                {
                    check = true;
                }
                else
                {
                    check = false;
                }
            }
        }
    }
    else if (n < 9)
    {

        Top_StackGame(n, k);

        if (Full_StackGame(n))
        {
            check = false;
        }
        else if (Empty_StackGame(n))
        {
            check = true;
        }
        else if (x.value + 1 == k.value & x.color != k.color)
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
    else if (n < 13)
    {

        if (Empty_Freecells(n))
        {
            check = true;
        } else {
            check = false;
        }
    }
    else
    {
        check = false;
    }

    return check;

}

bool Game::End_Game(){
    Card x;
    int top;
    int count = 0;

    for(int i = 1; i < 13; i++){
        int count2 = 0;

        if(i < 9){
            Top_StackGame(i, x);
        } else{
            x = free_cells[i - 9];
        }

        for(int j = 0; j < 13; j++){
            if(!No_Move(x, j)){
                count2++;
            }
        }

        if(count2 == 13){
            count++;
        }
    }

    if(count == 12){
        Show_Game();

        cout<<endl<<"---------------------------------------------------"<<endl;
        cout<<"        Que Pena!Voce ficou sem movimentos!        "<<endl;
        cout<<"---------------------------------------------------"<<endl<<endl;
        return true;
    } else {
        count = 0;
    }

    for(int i = 0; i < 4; i++){

        if(Full_StackExit(i)){
            count++;
            
        }
    }

    if(count == 4){
        Show_Game();
        cout<<endl<<"---------------------------------------------------"<<endl;
        cout<<"            Parabens!Voce venceu o jogo!           "<<endl;
        cout<<endl<<"---------------------------------------------------"<<endl;
        return true;
    } else {
        return false;
    }

    
}