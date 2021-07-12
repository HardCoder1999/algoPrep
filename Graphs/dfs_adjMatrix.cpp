#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &mat, vector<int> &visited, int start, int n) {
	// Base Case
	visited[start] = 1;

	cout << start << " ";

	for(int i=0; i<n; i++)
		if(mat[start][i] == 1 and visited[i] != 1)
			dfs(mat, visited, i, n);
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
	vector<int> visited(6);
	int start = 0, n = mat.size();
	dfs(mat, visited, start, n);
	cout << endl;
	return 0;
}