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

Node* rotateLeft(Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    Node* temp = head;
    int len = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0)
        return head;

    temp->next = head;

    Node* curr = head;
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }

    Node* newHead = curr->next;
    curr->next = NULL;

    return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << " positions: ";
    printList(head);

    return 0;
}
