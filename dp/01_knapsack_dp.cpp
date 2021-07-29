#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<vector<int>> &dp, vector<int> &wt, vector<int> &val, int W, int n) {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=W; j++)
			dp[i][j] = (j < wt[i-1]) ? dp[i-1][j] : max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);

	return dp[n][W];
}

int main(){
	int n, W;
	cin >> n;

	vector<int> wt(n), val(n);
	for(int i=0; i<n; i++) cin >> wt[i];
	for(int i=0; i<n; i++) cin >> val[i];

	cin >> W;

	vector<vector<int>> dp(n+1, vector<int>(W+1));

	cout << knapsack(dp, wt, val, W, n) << endl;
	return 0;
}