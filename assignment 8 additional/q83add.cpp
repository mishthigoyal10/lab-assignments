#include <iostream>
#include <queue>
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

Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if(i < n && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int maxDepth(Node* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + (left > right ? left : right);
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while(T--) {
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;

        int arr[n];
        cout << "Enter values in level order (-1 for NULL): ";
        for(int i = 0; i < n; i++) cin >> arr[i];

        Node* root = buildTree(arr, n);
        int depth = maxDepth(root);

        cout << "Maximum Depth: " << depth << endl;
    }

    return 0;
}
