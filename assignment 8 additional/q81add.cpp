#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(int arr[], int n, int i) {
    if(i >= n || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}

int sumLeftLeaves(Node* root, bool isLeft) {
    if(root == NULL) return 0;
    if(!root->left && !root->right && isLeft) return root->data;
    return sumLeftLeaves(root->left, true) + sumLeftLeaves(root->right, false);
}

int main() {
    int n;
    cout << "Enter number of nodes in the tree: ";
    cin >> n;

    int arr[n];
    cout << "Enter tree values in level order (-1 for NULL): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr, n, 0);

    int ans = sumLeftLeaves(root, false);

    cout << "Sum of left leaves is: " << ans;
    return 0;
}

