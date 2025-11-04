#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


int sizeOfDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int sizeOfCircular(Node* head) {
    if (head == NULL) return 0;
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {

    Node* headD = new Node(10);
    headD->next = new Node(20);
    headD->next->prev = headD;
    headD->next->next = new Node(30);
    headD->next->next->prev = headD->next;
    headD->next->next->next = new Node(40);
    headD->next->next->next->prev = headD->next->next;

    Node* headC = new Node(5);
    headC->next = new Node(15);
    headC->next->next = new Node(25);
    headC->next->next->next = new Node(35);
    headC->next->next->next->next = headC; 

    cout << "Size of Doubly Linked List: " << sizeOfDoubly(headD) << endl;
    cout << "Size of Circular Linked List: " << sizeOfCircular(headC) << endl;

    return 0;
}
