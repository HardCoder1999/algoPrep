#include <bits/stdc++.h>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

void rightView(node* root, int &currHeight, int level) {
	if(!root) return;

	if(currHeight < level) {
		cout << root->data << " ";
		currHeight = level;
	}
	rightView(root->right, currHeight, level+1);
	rightView(root->left, currHeight, level+1);
}

node* createNode(int data) {
	node* newNode = new node();

	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}



int main() {
	node* root = createNode(23);
	root->left = createNode(34);
	root->right = createNode(45);
	root->left->left = createNode(56);
	root->left->right = createNode(67);
	root->right->left = createNode(78);
	root->right->right = createNode(89);
	
	int currHeight = 0;
	rightView(root, currHeight, 1);
	cout << endl;
	return 0;
}