#include<iostream>
#include<stack>

using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
	};

class ExpTree{
	public:
	Node* root;

	bool isOperator(char x);
	Node* createNode(char data);
	Node* createTree(string s);
	void Delete(Node* root);
	void PostOrder(Node* root);
};

bool ExpTree:: isOperator(char x){
	return x == '+' || x== '-' || x== '/' || x== '*' ;
}

Node* ExpTree::createNode(char data){
	Node* newnode = new Node();
	if(!newnode){
		cout<<"\n Memory Error";
		return NULL;
	}
	else{
		newnode->data = data;
		newnode->left = newnode->right = NULL;	
	}
	return newnode;
}

Node* ExpTree::createTree(string s){
	stack<Node*> st;
	int length = s.size();
	for(int i = length -1; i>=0 ; i--){
		if(isOperator(s[i])){
			Node* op1 = st.top();
			st.pop();
			Node* op2 = st.top();
			st.pop();

			Node* newnode = createNode(s[i]);
			newnode->left = op1;
			newnode->right = op2;

			st.push(newnode);
		}
		else{
			Node* newnode = createNode(s[i]);
			st.push(newnode);
		}
	}
	


	return st.top();
}

void ExpTree::PostOrder(Node* root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";	
	}	
}

void ExpTree::Delete(Node* root){
	if(!root) return;
	Delete(root->left);
	Delete(root->right);
	delete root;
}


int main(){
ExpTree tree;
string prefix;
cout<<"\n Enter Prefix String: ";
cin>>prefix;

tree.root = tree.createTree(prefix);

cout<<"\n PostOrder Traversal: ";
tree.PostOrder(tree.root);
tree.Delete(tree.root);
	
return 0;}