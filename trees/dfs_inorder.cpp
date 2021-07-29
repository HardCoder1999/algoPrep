#include <bits/stdc++.h>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

node* create_node(int data) {
	node* newNode = new node();

	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void dfs_inorder(node* root) {
	if(root == NULL) return;

	dfs_inorder(root->left);
	cout << root->data << " ";
	dfs_inorder(root->right);
}


int main(){
	node* root = create_node(23);
	root->left = create_node(34);
	root->right = create_node(45);
	root->left->left = create_node(56);
	root->left->right = create_node(67);
	root->right->left = create_node(78);
	root->right->right = create_node(89);

	dfs_inorder(root);
	cout << endl;
	return 0;
}