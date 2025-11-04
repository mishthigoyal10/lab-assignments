#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) { head = newNode; return; }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != NULL) { cout << temp->data << "->"; temp = temp->next; }
    cout << "NULL\n";
}

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

int main() {
    int arr[] = {1,2,3,4};
    for(int i=0;i<4;i++) insertEnd(arr[i]);
    cout << "Original List: "; display();
    reverseList();
    cout << "Reversed List: "; display();
    return 0;
}
