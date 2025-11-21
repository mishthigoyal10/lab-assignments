#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* t = new Node();
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Node* insert(Node* root, int x) {
    if(root == NULL) return createNode(x);
    if(x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

int main() {
    int n, x, key;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    cin >> key;
    Node* ans = searchRecursive(root, key);
    if(ans) cout << "Found";
    else cout << "Not Found";
    return 0;
}
