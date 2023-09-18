#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
    top = 0;
}

Stack::~Stack(){
    cout<<"Chamado destrutor"<<endl;
}

bool Stack::Full(){
    return top == MaxStack;
}

bool Stack::Empty(){
    return top == 0;
}

void Stack::Push(int x){
    if(Full()){
        cout<<"A pilha esta cheia!Elemento "<<x<<" nao inserido!"<<endl;
        //abort(); finaliza a execução do código todo
        return;

    }
    top++;
    Entry[top] = x;
}

void Stack::Pop(int &x){
    if(Empty()){
        cout<<"A pilha está vazia!Elemento  "<<x<<" nao pode ser removido!"<<endl;
        return;
    }
    x = Entry[top];
    top--;
}

void Stack::Top(int &x){
    if(Empty()){
        cout<<"A pilha está vazia!Não há elemento no topo "<<endl;
        return;
    }
    Pop(x);
    Push(x);
}

/*
    void Stack::Top(int &x){
        if(top == 0){
            cout<<"A pilha está vazia!Não há elemento no topo "<<endl;
            return;
        }
        x = Entry[top];
    }
*/

void Stack::Clear(int &x){
    while(!Empty()){
        Pop(x);
    }
    cout<<"A pilha está vazia!Não há elementos "<<endl;
}

/*
    void Stack::Clear(){
        top = 0;
    }
*/

void Stack::Size(int &x){
    x = top;
}

