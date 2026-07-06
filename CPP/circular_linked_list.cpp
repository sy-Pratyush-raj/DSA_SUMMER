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

 void insertAtEnd(Node* &head, int val) {
    Node* node = new Node(val);

    if (head == NULL) {
        head = node;
        node->next = head;
        return;
    }
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
}

void deleteAtBeginning(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    Node* del = head;
    head = head->next;
    temp->next = head;
    delete del;
}

void printist(Node* head){
    Node* temp =head;
    do{
        cout<< temp->data <<" ->";
        temp = temp->next;
    }while(temp != head);
}

 int main(){

 }