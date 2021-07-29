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

void level_bfs(node* root) {
	if(!root) return;
	queue<pair<node*, int>> q;
	node* curr = root;
	q.push({root, 0});
	while(!q.empty()) {
		pair<node*, int> temp = q.front();
		q.pop();
		if(temp.first->left) q.push({ temp.first->left, temp.second+1 });
		if(temp.first->right) q.push({ temp.first->right, temp.second+1 });

		cout << temp.first->data << " " << temp.second << endl;
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
	
	level_bfs(root);
	cout << endl;
	return 0;
}