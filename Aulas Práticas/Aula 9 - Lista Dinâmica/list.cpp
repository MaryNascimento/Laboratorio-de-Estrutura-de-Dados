#include "list.h"
#include <iostream>

using namespace std;

List::List(){
    count = 0;
    head = NULL;
}

List::~List(){
    ListPointer q;

    while(head != NULL){
        q = head;
        head = head->NextNode;
        delete q;
    }
}

void List::Clear(){
    ListPointer q;

    while(head != NULL){
        q = head;
        head = head->NextNode;
        delete q;
    }

    count = 0;

}

bool List::Empty(){
    return count == 0;
}

bool List::Full(){
    return false;
}

void List::SetPosition(int p, ListPointer &current){
    //verificar se a posição é válida - não obrigatório
    current = head;

    for(int i = 2; i<=p ; i++){
        current = current->NextNode;

    }
}

void List::Insert(int p, int x){
    ListPointer NewNode, current;

    if(p < 1 || p > count + 1){
        cout<<"Posição não válida"<<endl;
        return;
    }

    NewNode = new ListNode;

    if(NewNode == NULL){
        cout<<"Falha na alocação"<<endl;
        return;
    }

    NewNode->Entry = x;
    SetPosition(p-1, current); //endereço anterior

    if(p == 1){
        NewNode->NextNode = head;
        head = NewNode;
        
    } else {
        NewNode->NextNode = current->NextNode;
        current->NextNode = NewNode;

    }
    count++;

}

void List::Delete(int p, int &x){
    ListPointer current, q;

    if(Empty()){
        cout<<"Lista Vazia"<<endl;
        return;
    }

    if(p < 1 || p > count){
        cout<<"Posição Inválida"<<endl;
        return;
    }

    if(p == 1){
        q = head;
        head = head->NextNode;
    } else {
        SetPosition(p - 1, current);
        q = current->NextNode;
        current->NextNode = q->NextNode;
    }
    
    x = q->Entry;
    delete q;
    count--;
}