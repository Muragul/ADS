#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue {
    public:
    Node *head, *tail;
    int size;

    Queue() {
        tail = head = NULL;
        size = 0;
    }
    bool Empty() {
        return size==0;
    }
    int Size(){
        return size;
    }
    void Print() {
        Node *node = new Node(0);
        node = head;
        while (node->next!=NULL){
            cout<<node->data<<"->";
            node = node->next;
        }
        cout<<node->data;
    }
    void Push(int data) {
        Node *node = new Node (data);
        if (Empty()){
            head = node;
        } else {
            tail->next = node;
        }
            tail = node;
            size++;
    }
    void Pop() {
        if (!Empty()){
            head = head ->next;
            size--;
        }
    }
    int Front() {
        return head->data;
    }
    void Clear(){
        tail = head = NULL;
        size = 0;
    }
};

int main(){
    int x;
    string s;
    cin>>s;
    Queue *q = new Queue();
    while (s!="exit"){
        if (s=="push"){
            cin>>x;
            q->Push(x);
            cout<<"ok";
        } else
        if (s=="pop"){
            cout<<q->Front();
            q->Pop();
        } else 
        if (s=="front")cout<<q->Front();
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