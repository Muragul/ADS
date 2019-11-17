#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(){
        this->data = 0;
        next = prev = NULL;
    }

    Node (int data) {
        this->data = data;
        next = prev = NULL;
    }
};

class LinkedList {
    public:
    Node *head, *tail;
    int size;

    LinkedList () {
        size = 0;
        head = tail = NULL;
    }

    int Size(){return size;}
    int First(){return head -> data;}
    int Last(){return tail->data;}
    bool Empty(){return size==0;}

    void PushFront(int data){
        Node *node  = new Node(data);
        if (Empty()){head = tail = node;} else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        size++;
    }
    void PushBack(int data){
        Node *node = new Node(data);
        if (Empty()){head = tail = node;} else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }
    void PopFront() {
        if (!Empty()){
            if (Size()==1){
                size = 0;
                head = tail = NULL;
            } else {
                head->next->prev = NULL;
                head = head->next;
                size--;
            }
        }
    }
    void PopBack() {
        if (!Empty()) {
            if (Size() == 1){
                size = 0;
                head = tail = NULL;
            } else {
                tail->prev->next = NULL;
                tail = tail->prev;
                size--;
            }
        }
    }
    void ReverseLinkedList(){
        LinkedList *list = new LinkedList();
        Node *node = new Node(0);
        node = head;
        for (int i=0;i<Size();i++){
            list->PushFront(node->data);
            node = node->next;
        }
        head=list->head;
        tail=list->tail;
    }
};

int main(){
    int n,k;
    LinkedList *l = new LinkedList();
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        if (s=="back"){
            if (l->Empty())cout<<";("<<endl; else {
            cout<<l->Last()<<endl;
            l->PopBack();
            }
        } else
        if (s=="front"){
            if (l->Empty())cout<<";("<<endl; else {
            cout<<l->First()<<endl;
            l->PopFront();
            }
        } else
        if (s=="push_back"){
            cin>>k;
            l->PushBack(k);
        } else
        if  (s =="push_front"){
            cin>>k;
            l->PushFront(k);
        } else
        if (s == "reverse"){
            l->ReverseLinkedList();
        }
    }
}