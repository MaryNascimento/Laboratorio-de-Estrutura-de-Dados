#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
    top = NULL;
    cont = 0;

}

bool Stack::Empty(){
    return top == NULL;

}

bool Stack::Full(){
    return false;

}

void Stack::Push(int x){
    StackNode* p;
    p = new StackNode;

    if(p == NULL){
        cout<<"Sem Memória Disponível"<<endl;
        return;
    }

    p -> Entry = x;
    p -> NextNode = top;
    top = p;
    cont++;

}

void Stack::Pop(int &x){
    if(Empty()){
        cout<<"Não há elementos para remover"<<endl;
        return;
    }

    StackNode* p;

    x = top -> Entry;
    p = top;
    top = top -> NextNode;

    delete p;
    cont--;

}

void Stack::Top(int &x){
    if(Empty()){
        cout<<"Pilha Vazia"<<endl;
        return;
    }

    x = top -> Entry;
}

void Stack::Clear(){
    int x;
    while(!Empty()){
        Pop(x);

    }
}

int Stack::Size(){
    return cont;

}

Stack::~Stack(){
    Clear();
}