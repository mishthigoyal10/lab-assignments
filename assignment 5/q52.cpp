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

int countKey(int key) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) count++;
        temp = temp->next;
    }
    return count;
}

void deleteAll(int key) {
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else temp = temp->next;
    }
}

int main() {
    int arr[] = {1,2,1,2,1,3,1};
    for(int i=0;i<7;i++) insertEnd(arr[i]);
    cout << "Original List: "; display();
    int key = 1;
    int c = countKey(key);
    cout << "Count: " << c << endl;
    deleteAll(key);
    cout << "Updated List: "; display();
    return 0;
}
