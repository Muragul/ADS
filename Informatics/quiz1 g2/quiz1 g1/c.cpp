#include <iostream>

using namespace std;

class Node {
    public:
    string data;
    Node *next, *prev;

    Node(){
        this->data = "";
        next = prev = NULL;
    }

    Node (string data) {
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
    string Front(){return head -> data;}
    string Back(){return tail->data;}
    bool Empty(){return size == 0;}

    void addFront(string data){
        Node *node  = new Node(data);
        if (Empty()){head = tail = node;} else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        size++;
    }
    void addBack(string data){
        Node *node = new Node(data);
        if (Empty()){head = tail = node;} else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }
    void eraseFront() {
        if (!Empty()){
            head->next->prev = NULL;
            head = head->next;
            size--;
        }
    }
    void eraseBack() {
        if (!Empty()) {
            tail->prev->next = NULL;
            tail = tail->prev;
            size--;
        }
    }
    void Print() {
        Node *node = new Node(0);
        node = head;
        while (node->next!=NULL){
            cout<<node->data<<"->";
            node = node->next;
        }
        cout<<node->data<<endl;
    }

    void Clear(){
        while (!Empty())eraseFront();
    }
};

int main(){
    LinkedList *l = new LinkedList();
    string s = "";
    while (cin>>s){
        if (s=="exit"){
            cout<<"goodbye";
            break;
        }
        string s1 = "";
        if (s=="add_front"){
                cin>>s1;
                l->addFront(s1);
        } else
        if (s=="add_back"){
                cin>>s1;
                l->addBack(s1);
        } else
        if (s=="erase_front")
                l->eraseFront();
        else
        if (s=="erase_back")
                l->eraseBack();
        if (s=="front")
                cout<<l->Front();
        if (s=="back")
                cout<<l->Back();
        if (s=="clear"){
                l->Clear();
                cout<<"OK";
        }
    }
}