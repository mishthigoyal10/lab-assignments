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

// ========== DOUBLY LINKED LIST FUNCTIONS ==========

void insertFirst(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertLast(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(Node* head, int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertBefore(Node*& head, int key, int val) {
    if (head == NULL) return;
    if (head->data == key) {
        insertFirst(head, val);
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteNode(Node*& head, int key) {
    if (head == NULL) return;
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
}

void search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node " << key << " not found!" << endl;
}

void display(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ========== CIRCULAR LINKED LIST FUNCTIONS ==========

void insertEndCircular(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void deleteCircular(Node*& head, int key) {
    if (head == NULL) return;

    Node* curr = head;
    Node* prev = NULL;

    while (curr->data != key) {
        if (curr->next == head) {
            cout << "Node not found!" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == head && curr->next == head) {
        head = NULL;
        delete curr;
        return;
    }

    if (curr == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = head->next;
        prev->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

void searchCircular(Node* head, int key) {
    if (head == NULL) {
        cout << "Empty list!" << endl;
        return;
    }
    Node* temp = head;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found!" << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node " << key << " not found!" << endl;
}

void displayCircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// ========== MAIN MENU ==========

int main() {
    Node* headD = NULL;
    Node* headC = NULL;
    int choice, val, key, type;

    cout << "1. Doubly Linked List\n2. Circular Linked List\nChoose type: ";
    cin >> type;

    do {
        cout << "\nMENU\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                if (type == 1) {
                    cout << "1.Insert First  2.Insert Last  3.After Node  4.Before Node: ";
                    int op; cin >> op;
                    if (op == 1) insertFirst(headD, val);
                    else if (op == 2) insertLast(headD, val);
                    else if (op == 3) { cout << "After which node? "; cin >> key; insertAfter(headD, key, val); }
                    else if (op == 4) { cout << "Before which node? "; cin >> key; insertBefore(headD, key, val); }
                } else {
                    insertEndCircular(headC, val);
                }
                break;

            case 2:
                cout << "Enter node to delete: ";
                cin >> key;
                if (type == 1) deleteNode(headD, key);
                else deleteCircular(headC, key);
                break;

            case 3:
                cout << "Enter node to search: ";
                cin >> key;
                if (type == 1) search(headD, key);
                else searchCircular(headC, key);
                break;

            case 4:
                if (type == 1) display(headD);
                else displayCircular(headC);
                break;
        }
    } while (choice != 5);

    return 0;
}
