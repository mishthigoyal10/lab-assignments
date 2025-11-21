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

int maxDepth(Node* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + (left > right ? left : right);
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "How many values you want to insert in BST: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "Maximum depth of BST is: " << maxDepth(root);

    return 0;
}
