#include <iostream>

using namespace std;

class Node {
    public:
    char data;
    Node *ch[10];

    Node(char data){
        this->data = data;
        for (int i=0;i<10;i++)
            this->ch[i] = NULL;
    }
};

class Trie {
    public:
    Node *root;
    int cnt;

    Trie(){
        root = new Node(' ');
        cnt = 0;
    }

    void insert (char a, chas s){
        Node *cur = root;
            Node *node = new Node(s);
            cur->ch[a-'a']->ch[s-'a'] = node;
                cur = node;
                cnt++;
    }
};

int main(){
    int n,m;
    char a,b;
    Trie *trie = new Trie();
    for (int i=0;i<m;i++){
        cin>>a,b;
        trie->insert(a,b);
    }
    cout<<trie->cnt;
    return 0;
}