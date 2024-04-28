#include <iostream>
using namespace std;   
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->isThreaded = false;
    return newNode;
}

// Function to perform preorder threading
void preorderThread(Node* curr, Node*& prev) {
    if (curr == nullptr)
        return;

    // Process the current node
    if (prev != nullptr)
        prev->left = curr; // or prev->right depending on your threading scheme

    prev = curr;

    // Recurse for left and right subtrees
    preorderThread(curr->left, prev);
    preorderThread(curr->right, prev);
}
// Function to perform preorder traversal using threads
void preorderTraversal(Node* root) {
    Node* curr = root;
    while (curr) {
        cout << curr->data << " ";

        // If the left child is not null, move to the left child
        if (curr->left)
            curr = curr->left;
        // If the left child is null, move to the right child
        else
            curr = curr->right;
    }
}

int main() {
    // Create a binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform preorder threading
    Node* prev = nullptr;
    preorderThread(root, prev);

    // Perform preorder traversal using threads
    cout << "Preorder Traversal: ";
    preorderTraversal(root);

    return 0;
}