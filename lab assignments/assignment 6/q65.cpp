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

bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = head1;

    Node* head2 = new Node(5);
    head2->next = new Node(15);
    head2->next->next = new Node(25);

    if (isCircular(head1))
        cout << "List 1 is a Circular Linked List" << endl;
    else
        cout << "List 1 is NOT a Circular Linked List" << endl;

    if (isCircular(head2))
        cout << "List 2 is a Circular Linked List" << endl;
    else
        cout << "List 2 is NOT a Circular Linked List" << endl;

    return 0;
}
