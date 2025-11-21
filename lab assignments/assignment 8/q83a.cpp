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
    if(root == NULL) {
        return createNode(x);
    }

    if(x < root->data) {
        root->left = insertNode(root->left, x);
    }
    else if(x > root->data) {
        root->right = insertNode(root->right, x);
    }
    else {
        cout << x << " is a duplicate and will not be inserted.\n";
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "How many values you want to insert: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);

    return 0;
}
