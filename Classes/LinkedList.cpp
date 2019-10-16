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
    void Print() {
        Node *node = new Node(0);
        node = head;
        while (node->next!=NULL){
            cout<<node->data<<"->";
            node = node->next;
        }
        cout<<node->data<<endl;
    }
    
    void Delete(int data){
        Node *node = new Node(data);
        node = head;
        if (data>Size()||data==0){
            cout<<"No such element";
            return;
        };
        if (data==1)PopFront();
         else 
        if (data==Size())PopBack(); else
        {
        for (int i=1;i<data;i++){
            node = node->next;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        size--;
        }
        Print();
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

    void insertNode(int data, int position){
        Node *node = new Node(0);
        Node *node_new = new Node(data);
        if (position==1)PushFront(data); else
        if (position==Size()+1)PushBack(data); else
        {
            node = head;
            for (int i=1;i<position;i++){
                node = node->next;
            }
            node->prev->next = node_new;
            node_new->prev = node->prev;
            node_new->next = node;
            node->prev = node;
            size++;
        }

    }

};
int main() {
    LinkedList *l = new LinkedList();
    int a;
    cin>>a;
    l->PushFront(1);
    l->PushFront(2);
    // l->PushFront(3);
    // l->PushBack(4);
    // l->PushBack(5);
    // l->PushBack(6);
    l->PopFront();
    l->PopBack();
    cout<<"OK";
    // cout<<"SIZE "<<l->Size()<<" ";
    // cout<<"FIRST "<<l->First()<<" ";
    // cout<<"LAST "<<l->Last()<<endl;
    // l->Print();
    // l->Delete(1);
    // l->insertNode(7,3);
    // l->Print();
    // l->ReverseLinkedList();
    // l->Print();
}