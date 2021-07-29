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

void topView(node* root, int &leftDepth, int &rightDepth, int level) {
	if(!root) return;

	
	topView(root->left, leftDepth, rightDepth, level+1);
	topView(root->right, leftDepth, rightDepth, level+1);
}

int main() {
	node* root = createNode(23);
	root->left = createNode(34);
	root->right = createNode(45);
	root->left->left = createNode(56);
	root->left->right = createNode(67);
	root->right->left = createNode(78);
	root->right->right = createNode(89);
	
	
	cout << endl;
	return 0;
}