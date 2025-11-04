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

void findMiddle() {
    if (head == NULL) { cout << "List is empty\n"; return; }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle: " << slow->data << endl;
}

int main() {
    int arr[] = {1,2,3,4,5};
    for(int i=0;i<5;i++) insertEnd(arr[i]);
    findMiddle();
    return 0;
}
