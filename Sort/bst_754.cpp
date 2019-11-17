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

    BST(){
        root = NULL;
    }

    Node *insert_node(Node *node, int data){
        if (node == NULL)node = new Node(data); else
        if (node->data>data)
            node->left = insert_node(node->left,data); 
            else
            node->right = insert_node(node->right,data);
        return node;
    }

    void inOrder(Node *node){
        if (node==NULL)return;
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

};

int main(){
    BST *bst = new BST();
    long int n,k;
    cin>>n;
    for (long int i=0;i<n;i++){
        cin>>k;
        bst->root = bst->insert_node(bst->root, k);
    }
    bst->inOrder(bst->root);
}