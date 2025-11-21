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

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, unordered_map<int,int>& indexMap, int& postIndex) {
    if (start > end) return NULL;

    int curr = postorder[postIndex--];
    Node* node = new Node(curr);

    int pos = indexMap[curr];

    node->right = buildTree(inorder, postorder, pos + 1, end, indexMap, postIndex);
    node->left = buildTree(inorder, postorder, start, pos - 1, indexMap, postIndex);

    return node;
}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++) cin >> postorder[i];

    unordered_map<int,int> indexMap;
    for (int i = 0; i < n; i++) indexMap[inorder[i]] = i;

    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, indexMap, postIndex);

    cout << "Preorder of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
