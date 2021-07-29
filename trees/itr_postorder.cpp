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

void postorder(node* root) {
	if(!root) return;
	stack<node*> s1, s2;
	node* curr = root;
	s1.push(curr);

	while(!s1.empty()) {
		node *temp = s1.top();
		s2.push(temp);
		s1.pop();

		if(temp->left) s1.push(temp->left);
		if(temp->right) s1.push(temp->right);
	}

	while(!s2.empty()){
		cout << s2.top()->data << " ";
		s2.pop();
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
	
	postorder(root);
	cout << endl;
	return 0;
}