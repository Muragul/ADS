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
    int max;

    Stack() {
        size = 0;
        top = NULL;
    }
    int getMax(){
        Node *node = new Node(0);
        node = top;
        int max = node->data;
        while (node->next!=NULL){
            if (node->data>max)max=node->data;
            node=node->next;
        }
        return max;
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
};

int main(){
    int n,k;
    string s="";
    cin>>n;
    Stack *stack = new Stack();
    for (int i=0;i<n;i++){
        cin>>s;
        if (s=="add"){
            cin>>k;
            stack->Push(k);
        } else
        if (s=="delete")stack->Pop(); else
        if (s=="getcur")
            if (stack->Empty())cout<<"error"; else
            cout<<stack->Top()<<endl; else
        if (s=="getmax")
            if (stack->Empty())cout<<"error"; else
            cout<<stack->getMax()<<endl;
    }
}