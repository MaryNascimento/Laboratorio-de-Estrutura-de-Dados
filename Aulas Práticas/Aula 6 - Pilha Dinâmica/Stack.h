#ifndef STACK_H
#define STACK_H

class Stack{
    public:

    Stack();
    ~Stack();
    void Push(int x);
    void Pop(int &x);
    bool Empty();
    bool Full();
    void Top(int &x);
    int Size();
    void Clear();

    private:
    
    struct StackNode{
        int Entry;
        StackNode* NextNode;

    };
    typedef StackNode* StackPointer;
    StackPointer top;
    int cont;

};

#endif