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

Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i >= arr.size()) break;

        if (arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

vector<int> rightView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* temp = q.front();
            q.pop();
            if (i == sz - 1) ans.push_back(temp->data);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return ans;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter number of nodes (including -1 for NULL): ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the nodes in level order: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        Node* root = buildTree(arr);
        vector<int> r = rightView(root);

        cout << "Right view: ";
        for (int x : r) cout << x << " ";
        cout << endl;
    }
    return 0;
}
