#include <iostream>

using namespace std;

class Node {
    public:
    char data;
    Node *next;

    Node(char data){
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
    char Top() {
        return top->data;
    }
    int Size() {
        return size;
    }
    void Push(char data){
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

Stack *stack = new Stack();

bool checkSequence(string s){
    int l = s.length();
    for (int i=0;i<l;i++){ //0 1 2 3 4 5 6
        if (s[i]=='[' || s[i]=='(' || s[i]=='{')
            stack->Push(s[i]);
        else {
            if (stack->Empty())return false;
            char ch = stack->Top();
            if (ch=='[' && s[i]!=']')return false; else
            if (ch=='{' && s[i]!='}')return false; else
            if (ch=='(' && s[i]!=')')return false;
            stack -> Pop();
        }
    }
    return stack->Empty();
}

int main(){
    string s;
    cin>>s;
    if (checkSequence(s))cout<<"ok"; else
    cout<<"not ok";
}