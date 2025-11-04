#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfter(int target, int val) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            Node* newNode = new Node;
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Target not found\n";
}

void deleteBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) { delete head; head = NULL; return; }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int val) {
    if (head == NULL) return;
    if (head->data == val) { deleteBeginning(); return; }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;
    if (temp->next == NULL) cout << "Node not found\n";
    else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, target;
    while (1) {
        cout << "\n1.Insert Beginning 2.Insert End 3.Insert After 4.Delete Beginning\n";
        cout << "5.Delete End 6.Delete Node 7.Search 8.Display 9.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; insertBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertEnd(val); break;
            case 3: cout << "Enter target: "; cin >> target; cout << "Enter value: "; cin >> val; insertAfter(target,val); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: cout << "Enter value: "; cin >> val; deleteNode(val); break;
            case 7: cout << "Enter value: "; cin >> val; searchNode(val); break;
            case 8: display(); break;
            case 9: return 0;
            default: cout << "Invalid choice\n";
        }
    }
    return 0;
}


