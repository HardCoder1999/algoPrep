#include <bits/stdc++.h>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

node* createNode(int data) {
	node* newNode = new node();

	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void inorder(node* root) {
	if(!root) return;
	
	stack<node*> s;
	node* curr = root;
	while(!s.empty() or curr != NULL) {
		if(curr) {
			s.push(curr);
			curr = curr->left;
		}else {
			curr = s.top();
			s.pop();
			cout << curr->data << " "; 
			
			curr = curr->right;
		}
	}
}

int main() {
	node* root = createNode(23);
	root->left = createNode(34);
	root->right = createNode(45);
	root->left->left = createNode(56);
	root->left->right = createNode(67);
	root->right->left = createNode(78);
	root->right->right = createNode(89);
	
	inorder(root);
	cout << endl;
	return 0;
}