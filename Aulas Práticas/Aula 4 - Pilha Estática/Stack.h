#ifndef STACK_H
#define STACK_H

const int MaxStack = 100; //declaração de constante do tipo int

class Stack{
    public:
    Stack(); //construtor
    ~Stack(); //destrutor
    bool Full(); //se a pilha está cheia
    bool Empty(); //se a pilha está vazia
    void Push(int x); //adicina x ao topo da pilha
    void Pop(int &x); //remove x do topo da pilha e retorna à uma variável
    void Top(int &x); //apenas retorna o elemento do topo
    void Clear(int &x);
    void Size(int &x);

    private:
    int top;
    int Entry [MaxStack + 1];
};

#endif