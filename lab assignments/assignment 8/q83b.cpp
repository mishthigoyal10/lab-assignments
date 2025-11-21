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
    else cout << x << " is a duplicate and will not be inserted.\n";
    return root;
}

Node* findMin(Node* root) {
    while(root && root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int x) {
    if(root == NULL) return root;

    if(x < root->data) root->left = deleteNode(root->left, x);
    else if(x > root->data) root->right = deleteNode(root->right, x);

    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
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

    cout << "Enter value you want to delete: ";
    cin >> x;
    root = deleteNode(root, x);

    cout << "Inorder traversal after deletion: ";
    inorder(root);

    return 0;
}
