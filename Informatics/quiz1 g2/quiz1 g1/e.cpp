#include <iostream>

using namespace std;
int p[1000000];

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
    void Print() {
        Node *node = new Node(0);
        node = head;
        while (node->next!=NULL){
            cout<<node->data<<"->";
            node = node->next;
        }
        cout<<node->data;
    }
};

int main(){
    Queue *q = new Queue();
    int n,k,count;
    int cnt = 0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        q->Push(k);
    }
    p[0]=1;
    while (!q->Empty()){
        count = 0;  
        for (int i=0;i<q->Front();i++){
            if (p[i]==0)count++;
        }
        p[q->Front()]=1;
        if (count)cnt++;
        q->Pop();
    }
    cout<<n-cnt;
}