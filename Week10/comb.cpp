#include <iostream>
#include <algorithm>

using namespace std;

bool ans;

class Node {
    public:
    char data;
    Node *ch[26];
    bool isEnd;
    bool isLeave;

    Node(char data){
        this->data = data;
        this->isEnd = 0;
        for (int i=0;i<26;i++)
            this->ch[i] = NULL;
        this->isLeave = 0;
        this->isEnd = 0;
    }
};

class Trie {
    public:
    Node *root;

    Trie(){
        this->root = new Node(' ');
    }

    void insert(string s){
        Node *cur = root;
        for (int i = 0; i < s.size(); i++){
            if (cur->ch[s[i]-'a']!=NULL)
                cur = cur->ch[s[i]-'a'];
                else
                {
                    cur->isLeave = 0;
                    Node *node = new Node(s[i]);
                    cur->ch[s[i]-'a'] = node;
                    cur = node;
                    cur->isLeave = 1;
                }
        }
        cur->isEnd = 1;
    }

    
    int search(string s){
        int cnt = 0;
        Node *cur = root;
        for (int i=0;i<s.size();i++){
            if (cur->ch[s[i]-'a']==NULL && cur->isLeave==0){
                return 0;
            } else
            if (cur->isLeave==1)return cnt; else
            {
            cur = cur->ch[s[i]-'a'];
            if (cur->isEnd)cnt++;
            }
        }
        return cnt;
    }
};


int main(){
    Trie *trie = new Trie();
    int n;
    string s;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s;
        reverse(s.begin(),s.end());
        trie->insert(s);
    }
    cout<<"Command:"<<endl;
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<trie->search(s);
    return 0;
}