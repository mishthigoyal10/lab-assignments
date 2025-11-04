#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        Node* temp = NULL;

        if (poly1->pow == poly2->pow) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            temp = new Node(sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            temp = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            temp = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while (poly1 != NULL) {
        tail->next = new Node(poly1->coeff, poly1->pow);
        tail = tail->next;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        tail->next = new Node(poly2->coeff, poly2->pow);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return result;
}

void printPoly(Node* head) {
    while (head != NULL) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next != NULL) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    Node* poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    cout << "Polynomial 1: ";
    printPoly(poly1);
    cout << "Polynomial 2: ";
    printPoly(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPoly(sum);

    return 0;
}
