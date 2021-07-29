#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<vector<int>> &dp, vector<int> &wt, vector<int> &val, int W, int n) {
	if(n == 0 or W == 0) return 0;

	if(dp[n][W] != -1) return dp[n-1][W-1];

	dp[n][W] = max(val[n-1] + knapsack(dp, wt, val, W-wt[n-1], n-1), knapsack(dp, wt, val, W, n-1));

	return dp[n][W];
}

int main(){

	int n, W;
	cin >> n;

	vector<int> wt(n), val(n);
	for(int i=0; i<n; i++) cin >> wt[i];
	for(int i=0; i<n; i++) cin >> val[i];
	cin >> W;
	vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
	

	cout << knapsack(dp, wt, val, W, n) << endl;
	
	return 0;
}