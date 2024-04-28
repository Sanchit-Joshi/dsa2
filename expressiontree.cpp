#include <iostream>
#include <stack>
using namespace std;

// Node structure for the expression tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

// Function to construct an expression tree from prefix expression
Node* constructExpressionTree(string prefix) {
    stack<Node*> st;
    int length = prefix.size();

    // Traverse the prefix expression in reverse order
    for (int i = length - 1; i >= 0; i--) {
        // If the current character is an operator
        if (isOperator(prefix[i])) {
            // Pop two operands from the stack
            Node* operand1 = st.top();
            st.pop();
            Node* operand2 = st.top();
            st.pop();

            // Create a new node with the current operator
            Node* newNode = createNode(prefix[i]);

            // Assign the popped operands as children of the new node
            newNode->left = operand1;
            newNode->right = operand2;

            // Push the new node back to the stack
            st.push(newNode);
        }
        // If the current character is an operand
        else {
            // Create a new node with the current operand
            Node* newNode = createNode(prefix[i]);

            // Push the new node back to the stack
            st.push(newNode);
        }
    }

    // The final node in the stack will be the root of the expression tree
    return st.top();
}

// Function to perform non-recursive post-order traversal of the expression tree
void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> st;
    Node* current = root;

    while (true) {
        if (current != NULL) {
            st.push(current);
            current = current->left;
        }
        else {
            if (st.empty())
                break;
            if (st.top()->right == NULL) {
                current = st.top();
                st.pop();
                cout << current->data << " ";
                while (!st.empty() && current == st.top()->right) {
                    current = st.top();
                    st.pop();
                    cout << current->data << " ";
                }
            }
            if (!st.empty())
                current = st.top()->right;
            else
                current = NULL;
        }
    }
}

// Function to delete the entire expression tree
void deleteTree(Node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefix = "+--a*bc/def";

    // Construct the expression tree
    Node* root = constructExpressionTree(prefix);

    // Perform non-recursive post-order traversal
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Delete the entire tree
    deleteTree(root);

    return 0;
}