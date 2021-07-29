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

void preorder(node* root) {
	if(!root) return;
	stack<node*> s;
	node* curr = root;

	s.push(curr);

	while(!s.empty()) {
		node *temp = s.top();
		s.pop();

		if(temp->right) s.push(temp->right);
		if(temp->left) s.push(temp->left);

		cout << temp->data << " ";
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
	
	preorder(root);
	cout << endl;
	return 0;
}