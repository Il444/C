#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = createNode(value);
        return;
    }
    if (value < root->data) {
        insert(root->left, value);
    }
    else {
        insert(root->right, value);
    }
}

void buildTree(Node*& root) {
    int n, value;
    cout << "How many numbers? ";
    cin >> n;
    cout << "Enter " << n << " different integers: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(root, value);
    }
}

void printTree(Node* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int task8(Node* root) {
    if (root == nullptr) return 0;

    int leftDepth = task8(root->left);
    int rightDepth = task8(root->right);

    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    }
    else {
        return rightDepth + 1;
    }
}

int main() {
    Node* root = nullptr;

    buildTree(root);

    cout << "Tree: ";
    printTree(root);
    cout << endl;

    int depth = task8(root);
    cout << "Maximum depth: " << depth << endl;

    return 0;
}