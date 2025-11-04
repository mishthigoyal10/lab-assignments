#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int val) {
        data = val;
        next = prev = random = NULL;
    }
};


void correctRandomPointer(Node* head) {
    if (!head) return;

    unordered_set<Node*> visited;
    Node* current = head;
    Node* wrongNode = NULL;

 
    while (current) {
        if (current->random && (visited.find(current->random) != visited.end())) {
            wrongNode = current;
        }
        visited.insert(current);
        current = current->next;
    }

    if (wrongNode)
        wrongNode->random = wrongNode->next;

    cout << "Random pointer corrected successfully." << endl;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node " << temp->data << " ";
        if (temp->random)
            cout << "-> random points to " << temp->random->data << endl;
        else
            cout << "-> random points to NULL" << endl;
        temp = temp->next;
    }
}

int main() {
  
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    head->random = head->next;         
    head->next->random = head->next;  
    head->next->next->random = head;  

    cout << "Before correction:\n";
    printList(head);

    correctRandomPointer(head);

    cout << "\nAfter correction:\n";
    printList(head);

    return 0;
}
