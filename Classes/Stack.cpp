#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack {
    public:
    Node *top;
    int size;

    Stack() {
        size = 0;
        top = NULL;
    }
    bool Empty() {
        return size==0;
    }
    int Top() {
        return top->data;
    }
    int Size() {
        return size;
    }
    void Print() {
        Node *node = new Node(0);
        node = top;
        while (node->next!=NULL){
            cout<<node->data<<"->";
            node = node->next;
        }
        cout<<node->data;
    }
    void Push(int data){
        Node *node = new Node(data);
        if (Empty()){} else {
            node -> next = top;
        }
            top = node;
            size++;
    }
    void Pop(){
        if (!Empty()){
            top = top->next;
            size--;
        }
    }
    void Clear(){
        size = 0;
        top = NULL;
    }
};
int main(){
    Stack *q = new Stack();
    int x;
    string s;
    cin>>s;
    while (s!="exit"){
        if (s=="push"){
            cin>>x;
            q->Push(x);
            cout<<"ok";
        } else
        if (s=="pop"){
            cout<<q->Top();
            q->Pop();
        } else 
        if (s=="back")cout<<q->Top();
        else
        if (s=="size")cout<<q->Size();
         else
        if (s=="clear"){
            q->Clear();
            cout<<"ok";
        }
        cin>>s;
    }
    cout<<"bye";
}