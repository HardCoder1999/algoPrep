#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &adjList, int start){
	int n = adjList.size();
	queue<int> q;
	vector<int> visited(n);
	q.push(start);
	visited[start] = 1;
	while(!q.empty()){
		int currVertex = q.front();
		q.pop();
		for(int i=0; i<adjList[currVertex].size(); i++){
			if(visited[adjList[currVertex][i]] == 0){
				q.push(adjList[currVertex][i]);
				visited[adjList[currVertex][i]] = 1;
			}
		}
		cout << currVertex << " ";
	}
	cout << endl;
}

int main(){
	vector<vector<int>> list = {
		{1, 2, 3},
		{0, 3, 4},
		{0, 3, 5},
		{0, 1, 2, 4, 5},
		{1, 3, 5},
		{2, 3, 4}
	};

	bfs(list, 1);
	return 0;
}