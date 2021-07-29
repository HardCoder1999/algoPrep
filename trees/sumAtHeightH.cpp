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

int maxDepth(node* root) {
	return !root ? 0 : 1+max(maxDepth(root->left), maxDepth(root->right));
}

int sum = 0;

int sumAtHeight(node* root, int height, int currHeight) {
	if(!root) return 0;

	if(currHeight == height) return sum += root->val;
	return (sumAtHeight(root->left, height, currHeight+1) 
		+ sumAtHeight(root->right, height, currHeight+1));
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