#include <bits/stdc++.h>

using namespace std;

// Graph traversal
void bfs(vector<vector<int>> &mat, int start){
	int n = mat.size();
	queue<int> q;
	vector<int> visited(n);
	q.push(start);
	visited[start] = 1;
	while(!q.empty()){
		int currVertex = q.front();
		q.pop();

		for(int i=0; i<n; i++){
			if(mat[currVertex][i] == 1 and visited[i] == 0){
				visited[i] = 1;
				q.push(i);
			}
		}
		cout << currVertex << " ";
	}
	cout << endl;
}

int main(){
	vector<vector<int>> mat = {
   		{0, 1, 1, 1, 0, 0},
   		{1, 0, 0, 1, 1, 0},
   		{1, 0, 0, 1, 0, 1},
   		{1, 1, 1, 0, 1, 1},
   		{0, 1, 0, 1, 0, 1},
   		{0, 0, 1, 1, 1, 0}
	};

	bfs(mat, 1);
	return 0;
}