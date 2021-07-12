#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &list, vector<int> &visited, int start) {
	visited[start] = 1;

	cout << start << " ";

	for(int i=0; i<list[start].size(); i++)
		if(visited[list[start][i]] == 0)
			dfs(list, visited, list[start][i]);
}

int main() {
	vector<vector<int>> list = {
		{1, 2, 3},
		{0, 3, 4},
		{0, 3, 5},
		{0, 1, 2, 4, 5},
		{1, 3, 5},
		{2, 3, 4}
	};

	vector<int> visited(6);

	int start = 0;
	dfs(list, visited, start);
	cout << endl;

	return 0;
}