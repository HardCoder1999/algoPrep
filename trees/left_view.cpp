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

void leftView(node* root, int &currHeight, int level) {
	if(!root) return;

	if(level > currHeight){
		cout << root->data << " ";
		currHeight = level;
	}
	leftView(root->left, currHeight, level+1);
	leftView(root->right, currHeight, level+1);
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
	leftView(root, currHeight, 1);
	cout << endl;
	return 0;
}