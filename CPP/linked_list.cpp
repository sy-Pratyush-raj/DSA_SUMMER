#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtBeginning(Node* &head, int val) {
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void insertAtEnd(Node * &head , int val){
    Node* node = new Node(val);
    if(head == NULL){
        head = node;
        return;
    }
    
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next = node;
}
int main(){
    Node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);

}