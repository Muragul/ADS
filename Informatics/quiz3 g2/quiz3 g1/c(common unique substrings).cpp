#include <iostream>

using namespace std;

class Node {
    public:
    char data;
    Node *ch[26];
    bool first;
    bool second;

    Node(char data){
        this->data = data;
        for (int i=0;i<26;i++)
            this->ch[i] = NULL;
        this->first = 0;
        this->second = 0;
        
    }
};

class Trie {
    public:
    Node *root;
    int cnt;

    Trie(){
        cnt = 0;
        root = new Node(' ');
    }

    void insert (string s, int n){
        Node *cur = root;
        for (int i=0;i<s.size();i++){
            if (cur->ch[s[i]-'a']!=NULL){
                cur=cur->ch[s[i]-'a'];
            }
            else
            {
                Node *node = new Node(s[i]);
                cur->ch[s[i]-'a'] = node;
                cur = node;
            }
            if (n==1)cur->first=1;
            if (n==2)cur->second=1;
        }
    }
    
    void search(Node *root){
        Node *cur = root;
        if (cur == NULL) return;
        if (cur->first == 1 && cur->second==1)cnt++;
        for (int i=0;i<26;i++)
            search(cur->ch[i]);
    }

};

int main(){
    string s,t;
    cin>>s>>t;
    Trie *trie = new Trie();
    for (int i=0;i<s.size();i++){
        string s1 = s.substr(i);
        trie->insert(s1,1);
    }
    for (int j=0;j<t.size();j++){
        string s2 = t.substr(j);
        trie->insert(s2,2);
    }
    trie->search(trie->root);
    cout<<trie->cnt;
    return 0;
}