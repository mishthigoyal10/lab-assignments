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

int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != NULL && headB != NULL) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(5);

    Node* listA = new Node(4);
    listA->next = new Node(1);
    listA->next->next = common;

    Node* listB = new Node(5);
    listB->next = new Node(6);
    listB->next->next = new Node(1);
    listB->next->next->next = common;

    Node* intersection = getIntersectionNode(listA, listB);

    if (intersection != NULL)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
