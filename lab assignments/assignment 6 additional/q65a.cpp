#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    Node* up;
    Node* down;
    Node(int val) {
        data = val;
        right = left = up = down = NULL;
    }
};

// Function to convert 2D matrix to 4-pointer doubly linked list
Node* convertToLinkedMatrix(vector<vector<int>> &mat, int n, int m) {
    if (n == 0 || m == 0) return NULL;

    vector<vector<Node*>> nodes(n, vector<Node*>(m, NULL));

    // Step 1: Create all nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    // Step 2: Connect pointers (up, down, left, right)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m)
                nodes[i][j]->right = nodes[i][j + 1];
            if (j - 1 >= 0)
                nodes[i][j]->left = nodes[i][j - 1];
            if (i + 1 < n)
                nodes[i][j]->down = nodes[i + 1][j];
            if (i - 1 >= 0)
                nodes[i][j]->up = nodes[i - 1][j];
        }
    }

    // Return top-left node
    return nodes[0][0];
}

// Function to print linked matrix row-wise
void printLinkedMatrix(Node* head) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = mat.size();
    int m = mat[0].size();

    Node* head = convertToLinkedMatrix(mat, n, m);

    cout << "Doubly Linked List (4-pointer form):" << endl;
    printLinkedMatrix(head);

    return 0;
}
