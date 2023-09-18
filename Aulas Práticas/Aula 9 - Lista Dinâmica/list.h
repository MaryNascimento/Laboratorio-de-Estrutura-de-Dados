#ifndef LIST_H
#define LIST_H

class List{
    public:
    List();
    ~List();
    void Insert(int p, int x);
    void Delete(int p, int &x);
    bool Full();
    bool Empty();
    int Size();
    void Clear();

    private:
    struct ListNode{
        int Entry;
        ListNode* NextNode;
    };
    typedef ListNode* ListPointer;

    ListPointer head;
    int count;

    void SetPosition(int p, ListPointer &current);
};
#endif