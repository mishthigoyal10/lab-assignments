#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;


    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {

    Node* head = new Node('R');
    head->next = new Node('A');
    head->next->prev = head;
    head->next->next = new Node('D');
    head->next->next->prev = head->next;
    head->next->next->next = new Node('A');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('R');
    head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        cout << "The Doubly Linked List is a Palindrome" << endl;
    else
        cout << "The Doubly Linked List is NOT a Palindrome" << endl;

    return 0;
}
