#include <iostream>

using namespace std;

class Node {
    public:
    char data;
    Node *ch[26];

    Node(char data){
        this->data = data;
        for (int i=0;i<26;i++)
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

    void insert (string s){
        Node *cur = root;
        for (int i=0;i<s.size();i++){
            if (cur->ch[s[i]-'a']!=NULL)
                cur=cur->ch[s[i]-'a'];
            else
            {
                Node *node = new Node(s[i]);
                cur->ch[s[i]-'a'] = node;
                cur = node;
                cnt++;
            }
            
        }
    }
};

int main(){
    string s;
    cin>>s;
    Trie *trie = new Trie();
    for (int i=0;i<s.size();i++){
        string s1 = s.substr(i);
        trie->insert(s1);
    }
    cout<<trie->cnt;
    return 0;
}