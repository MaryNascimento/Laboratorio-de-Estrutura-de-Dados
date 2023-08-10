#include <iostream>

using namespace std;

void swap(void* &left, void* &right){
    void* temp = left;
    left = right;
    right = temp;
}

int main(){

    void* left = new int[0];
    void* right = new int[0];

    cout<<"Antes: Left = "<<left<<" / Right: "<<right<<endl;

    swap(left, right);

    cout<<"Depois: Left = "<<left<<" / Right: "<<right<<endl;
}