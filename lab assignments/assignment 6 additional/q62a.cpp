#include <iostream>
using namespace std;

int findParity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// -------------------- DOUBLY LINKED LIST --------------------
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

void removeEvenParityDList(DNode** head_ref) {
    DNode* curr = *head_ref;

    while (curr) {
        int parity = findParity(curr->data);
        if (parity % 2 == 0) {
            DNode* temp = curr;

            if (curr->prev)
                curr->prev->next = curr->next;
            else
                *head_ref = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;

            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}

void printDList(DNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <=> ";
        head = head->next;
    }
    cout << endl;
}

// -------------------- CIRCULAR LINKED LIST --------------------
struct CNode {
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

void removeEvenParityCList(CNode** head_ref) {
    if (*head_ref == NULL)
        return;

    CNode* curr = *head_ref;
    CNode* prev = NULL;


    do {
        int parity = findParity(curr->data);
        if (parity % 2 == 0) {
            if (curr == *head_ref && curr->next == *head_ref) {

                delete curr;
                *head_ref = NULL;
                return;
            }
            if (curr == *head_ref) {
                CNode* temp = curr;
                while (temp->next != *head_ref)
                    temp = temp->next;
                temp->next = curr->next;
                *head_ref = curr->next;
                delete curr;
                curr = *head_ref;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != *head_ref);
}

void printCList(CNode* head) {
    if (!head)
        return;
    CNode* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << " -> ";
    } while (temp != head);
    cout << endl;
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    CNode* headC = new CNode(9);
    headC->next = new CNode(11);
    headC->next->next = new CNode(34);
    headC->next->next->next = new CNode(6);
    headC->next->next->next->next = new CNode(13);
    headC->next->next->next->next->next = new CNode(21);
    headC->next->next->next->next->next->next = headC;

    cout << "Original Circular Linked List:\n";
    printCList(headC);

    removeEvenParityCList(&headC);

    cout << "After removing even parity nodes:\n";
    printCList(headC);

    cout << "\n--------------------------------\n";

    DNode* headD = new DNode(18);
    headD->next = new DNode(15);
    headD->next->prev = headD;
    headD->next->next = new DNode(8);
    headD->next->next->prev = headD->next;
    headD->next->next->next = new DNode(9);
    headD->next->next->next->prev = headD->next->next;
    headD->next->next->next->next = new DNode(14);
    headD->next->next->next->next->prev = headD->next->next->next;

    cout << "Original Doubly Linked List:\n";
    printDList(headD);

    removeEvenParityDList(&headD);

    cout << "After removing even parity nodes:\n";
    printDList(headD);

    return 0;
}
