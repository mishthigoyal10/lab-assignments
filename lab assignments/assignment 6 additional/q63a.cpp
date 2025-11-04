#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1)
        return head;

    Node* current = head;
    Node* newHead = NULL;
    Node* temp = NULL;
    int count = 0;


    while (current && count < k) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        count++;
    }

 
    if (temp)
        newHead = temp->prev;

    if (current != NULL) {
        head->next = reverseInGroups(current, k);
        if (head->next)
            head->next->prev = head;
    }

    return newHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << " <-> NULL" << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    int k = 2;
    cout << "Original List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}



