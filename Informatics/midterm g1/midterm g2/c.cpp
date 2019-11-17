#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;

    Node (int data){
        this->data = data;
        left = right = NULL;
    }
};

class BST{
    public:
    Node *root;
    int cnt;

    BST(){
        root = NULL;
        cnt = 0;
    }

    Node *insert_node(Node *node, int data){
        if (node == NULL)node = new Node(data); else
        if (node->data>data)
            node->left = insert_node(node->left,data); 
            else
            node->right = insert_node(node->right,data);
    }

    int getCount(){
        return cnt;
    }

    void leafsCnt(Node *node){
        if (node->left==NULL && node->right==NULL){
            cnt++; return;
        } else
        if (node->left==NULL){
            leafsCnt(node->right);
         } else
        if (node->right==NULL){
            leafsCnt(node->left);
        } else {
        leafsCnt(node->left);
        leafsCnt(node->right);
        }
    }
};

int main(){
    int n,k;
    cin>>n;
    BST *Tree = new BST();
    for (int i=0;i<n;i++){
        cin>>k;
        Tree->root = Tree->insert_node(Tree->root, k);
    }
    Tree->leafsCnt(Tree->root);
    cout<<Tree->getCount();
}