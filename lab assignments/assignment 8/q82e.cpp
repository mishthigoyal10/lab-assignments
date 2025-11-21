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
    while(root && root->right != NULL) root = root->right;
    return root;
}

Node* findPredecessor(Node* root, int val) {
    Node* predecessor = NULL;
    Node* current = root;

    while(current != NULL) {
        if(val > current->data) {
            predecessor = current;
            current = current->right;
        }
        else if(val < current->data) {
            current = current->left;
        }
        else {
            if(current->left != NULL) {
                predecessor = findMax(current->left);
            }
            break;
        }
    }

    return predecessor;
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

    int key;
    cout << "Enter the value whose in-order predecessor you want: ";
    cin >> key;

    Node* ans = findPredecessor(root, key);

    if(ans == NULL) {
        cout << "Predecessor does not exist or value not found.";
    } else {
        cout << "In-order predecessor of " << key << " is: " << ans->data;
    }

    return 0;
}
