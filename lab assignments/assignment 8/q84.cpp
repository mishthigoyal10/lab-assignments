#include <iostream>
#include <vector>
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

// Build tree using array representation
Node* buildTree(vector<int>& arr, int index, int n) {
    if(index >= n || arr[index] == -1) return NULL;

    Node* root = createNode(arr[index]);
    root->left = buildTree(arr, 2 * index + 1, n);
    root->right = buildTree(arr, 2 * index + 2, n);
    return root;
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000000, 1000000000);
}

int main() {
    int n;
    cout << "Enter number of nodes in tree: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values level wise (use -1 for empty):\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr, 0, n);

    if(isBST(root)) {
        cout << "This tree IS a BST.";
    } else {
        cout << "This tree is NOT a BST.";
    }

    return 0;
}
