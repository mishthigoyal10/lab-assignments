#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* n = new Node();
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insertNode(Node* root, int x) {
    if(root == NULL) return createNode(x);
    if(x < root->data) root->left = insertNode(root->left, x);
    else if(x > root->data) root->right = insertNode(root->right, x);
    return root;
}

Node* findMax(Node* root) {
    if(root == NULL) return NULL;
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "How many values you want to insert in BST: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> x;
        root = insertNode(root, x);
    }

    Node* ans = findMax(root);
    if(ans == NULL) {
        cout << "Tree is empty.";
    } else {
        cout << "Maximum value in BST is: " << ans->data;
    }

    return 0;
}
