#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    Node *parent;

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
    }

    Node *findMin(Node *node){
        while (node->left!=NULL)
        node = node->left;
        return node;
    }
    Node *findMax(Node *node){
        while (node->right!=NULL)
        node = node->right;
        return node;
    }

    void inOrder(Node *node){
        if (node==NULL)return;
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    Node *deleteNumber(Node *node, int data){
        if (node==NULL)return NULL;
        if (node->data>data)
            node->left = deleteNumber(node->left, data); else
        if (node->data<data)
            node->right = deleteNumber(node->right, data); 
        else {
            if (node->right==NULL && node->left==NULL)
                node = NULL; else
            if (node->left == NULL)
                node = node->right; else
            if (node->right == NULL)
                node = node->left; else {
                    Node *t = findMin(node->right);
                    node->data = t->data;
                    node->right = deleteNumber(node->right,t->data);
                }
        }
        return node;
    }

};

int main(){
    BST *Tree = new BST();
    Tree->root = Tree->insert_node(NULL, 8);
    Tree->root = Tree->insert_node(Tree->root, 10);
    Tree->root = Tree->insert_node(Tree->root, 7);
    Tree->root = Tree->insert_node(Tree->root, 5);
    Tree->root = Tree->insert_node(Tree->root, 3);
    Tree->root = Tree->insert_node(Tree->root, 15);
    cout<<Tree->root->right->data<<endl;
    cout<<Tree->findMin(Tree->root)->data<<endl;
    cout<<Tree->findMax(Tree->root)->data<<endl;
    Tree->inOrder(Tree->root);
    cout<<endl;
    Tree->root = Tree->deleteNumber(Tree->root,10);
    Tree->inOrder(Tree->root);
}