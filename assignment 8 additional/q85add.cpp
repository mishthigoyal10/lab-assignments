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

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int,int>& indexMap, int& preIndex) {
    if (start > end) return NULL;

    int curr = preorder[preIndex++];
    Node* node = new Node(curr);

    int pos = indexMap[curr];

    node->left = buildTree(preorder, inorder, start, pos - 1, indexMap, preIndex);
    node->right = buildTree(preorder, inorder, pos + 1, end, indexMap, preIndex);

    return node;
}

void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) cin >> preorder[i];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    unordered_map<int,int> indexMap;
    for (int i = 0; i < n; i++) indexMap[inorder[i]] = i;

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, indexMap, preIndex);

    cout << "Postorder of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
