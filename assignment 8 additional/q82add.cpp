#include <iostream>
#include <vector>
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

vector<Node*> generate(int start, int end) {
    vector<Node*> result;

    if(start > end) {
        result.push_back(NULL);
        return result;
    }

    for(int i = start; i <= end; i++) {
        vector<Node*> leftTrees = generate(start, i - 1);
        vector<Node*> rightTrees = generate(i + 1, end);

        for(Node* L : leftTrees) {
            for(Node* R : rightTrees) {
                Node* root = new Node(i);
                root->left = L;
                root->right = R;
                result.push_back(root);
            }
        }
    }
    return result;
}

void printTree(Node* root) {
    if(root == NULL) {
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<Node*> allTrees = generate(1, n);

    cout << "Unique BSTs are:\n";
    for(int i = 0; i < allTrees.size(); i++) {
        cout << "Tree " << i+1 << ": ";
        printTree(allTrees[i]);
        cout << endl;
    }

    return 0;
}
