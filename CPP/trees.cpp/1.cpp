#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root){
     if(root == NULL){
        return;
    }

    // Visit Root
    cout << root->data << " ";

    // Traverse Left Subtree
    preorder(root->left);

    // Traverse Right Subtree
    preorder(root->right);

}