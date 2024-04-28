#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    if (newNode)
    {
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}

Node *insertNode(Node *root, int value)
{
    if (root == nullptr)
    {
        root = createNode(value);
        return root;
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int findLongestPath(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftPath = findLongestPath(root->left);
    int rightPath = findLongestPath(root->right);

    return max(leftPath, rightPath) + 1;
}

int findMinimumValue(Node *root)
{
    if (root == nullptr)
    {
        cout << "Error: Tree is empty." << endl;
        return -1;
    }

    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root->data;
}

Node *swapLeftRight(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapLeftRight(root->left);
    swapLeftRight(root->right);

    return root;
}

bool searchValue(Node *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }
    else if (value < root->data)
    {
        return searchValue(root->left, value);
    }
    else
    {
        return searchValue(root->right, value);
    }
}

int main()
{
    Node *root = nullptr;

    // Construct binary search tree by inserting values
    // in the order given
    // Example:
    // root = insertNode(root, 5);
    // root = insertNode(root, 3);
    // root = insertNode(root, 7);
    // root = insertNode(root, 2);
    // root = insertNode(root, 4);
    // root = insertNode(root, 6);
    // root = insertNode(root, 8);

    int choice;
    int value;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Find number of nodes in longest path from root" << endl;
        cout << "3. Minimum data value found in the tree" << endl;
        cout << "4. Mirror" << endl;
        cout << "5. Search a value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            break;
        case 2:
            cout << "Number of nodes in longest path from root: " << findLongestPath(root) << endl;
            break;
        case 3:
            cout << "Minimum data value found in the tree: " << findMinimumValue(root) << endl;
            break;
        case 4:
            root = swapLeftRight(root);
            cout << "Tree modified successfully." << endl;
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            if (searchValue(root, value))
            {
                cout << "Value found in the tree." << endl;
            }
            else
            {
                cout << "Value not found in the tree." << endl;
            }
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}