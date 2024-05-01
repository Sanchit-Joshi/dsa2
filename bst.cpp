#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;


    node(){ //default constructor
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int val){ //parametrised constructor
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public:
    node* root;
    int cnt;

    BST(){
        root = NULL;
        cnt = 0;
    }

    void insert(int x); //  
    void min_node();//
    void max_node(); //
    void search(node* root, int key);
    void inorder(node* root); //
    void mirror(node* root); //


    int height(node*root , int&diameter){
        if(!root) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter,lh+rh); //updating diameter variable
    return 1+max(lh,rh); //returns height
    }
    
    int longestpath(node* root){
    int diameter = 0;
    this->height(root, diameter);
    return diameter-1;
    }
};

void BST::insert(int x){
    
    node*t = root;
    node*p , *q;

    if(root ==NULL){
        p = new node(x);
        root = p;
        return;
    }
    while( t != NULL){
        q = t;
        if(x < t->data) t = t->left;
        else if (x > t->data) t = t->right;
        else return;

    }
    p = new node(x);
    if(x < q->data) q->left = p;
    else q->right = p;

// time complexity : O(h)
}

void BST::inorder(node* root){
    if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}

void BST::min_node(){
    node* t = root;
    while(t->left){
        t = t->left;
    }
    cout<<"\n Smallest : "<<t->data;
}
void BST::max_node(){
    node*t = root;
    while(t->right){
        t = t->right;
    }
    cout<<"\n Largest: "<<t->data;
}

void BST::mirror(node* root){

    node* t;
    if(root){
        t = root->left;
        root->left = root->right;
        root->right = t;
        mirror(root->left);
        mirror(root->right);
    }
}

int main(){
    BST tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(35);
    tree.insert(15);
    tree.insert(25);
    tree.insert(33);
    tree.insert(37);
    tree.inorder(tree.root);
    tree.min_node();
    tree.max_node();

    cout<<"\n";
    tree.mirror(tree.root);
    tree.inorder(tree.root);
   cout<<endl<< tree.longestpath(tree.root);
    return 0;


    //check max height on every node
    //update max variable

    /*diameter
    height */
}