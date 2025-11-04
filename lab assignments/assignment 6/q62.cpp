#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void displayCircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << head->data << endl;  
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    head->next->next->next->next->next = head; 

    cout << "Circular Linked List values: ";
    displayCircular(head);

    return 0;
}
