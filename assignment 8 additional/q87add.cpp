#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else if (val > root->data) root->right = insertBST(root->right, val);
    return root;
}

void inorderStore(Node* root, vector<int>& arr) {
    if (!root) return;
    inorderStore(root->left, arr);
    arr.push_back(root->data);
    inorderStore(root->right, arr);
}

struct DLL {
    int data;
    DLL* prev;
    DLL* next;
    DLL(int x) {
        data = x;
        prev = next = NULL;
    }
};

DLL* makeDLL(vector<int>& arr) {
    if (arr.empty()) return NULL;
    DLL* head = new DLL(arr[0]);
    DLL* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        DLL* temp = new DLL(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    return head;
}

void printDLL(DLL* head) {
    while (head) {
        cout << head->data << " <--> ";
        head = head->next;
    }
    cout << "null\n";
}

int main() {
    int n1, n2;
    cout << "Enter number of nodes in first BST: ";
    cin >> n1;

    Node* root1 = NULL;
    cout << "Enter elements for first BST: ";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        root1 = insertBST(root1, x);
    }

    cout << "Enter number of nodes in second BST: ";
    cin >> n2;

    Node* root2 = NULL;
    cout << "Enter elements for second BST: ";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        root2 = insertBST(root2, x);
    }

    vector<int> a, b;
    inorderStore(root1, a);
    inorderStore(root2, b);

    vector<int> merged;
    merged.reserve(a.size() + b.size());

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);

    DLL* head = makeDLL(merged);

    cout << "Merged Sorted Doubly Linked List:\n";
    printDLL(head);

    return 0;
}
