#include <bits/stdc++.h>

using namespace std;

int ubKnapsackRecursive(vector<int> &wt, vector<int> &val, int W, int n) {
	if(W == 0 or n == 0) return 0;

	return W < wt[n-1] ? ubKnapsackRecursive(wt, val, W, n-1) : 
	max(val[n-1]+ubKnapsackRecursive(wt, val, W-wt[n-1], n), ubKnapsackRecursive(wt, val, W, n-1));
}

int ubKnapsackMemoized(vector<vector<int>> &dp, vector<int> &wt, vector<int> &val, int W, int n) {
	if(W == 0 or n == 0) return 0;

	if(dp[n][W] != -1) return dp[n][W];

	dp[n][W] = (W < wt[n-1]) ? ubKnapsackMemoized(dp, wt, val, W, n-1) : 
	max(ubKnapsackMemoized(dp, wt, val, W, n-1), val[n-1] + ubKnapsackMemoized(dp, wt, val, W-wt[n-1], n));

	return dp[n][W];
}

int ubKnapsackDp(vector<vector<int>> &dp, vector<int> &wt, vector<int> &val, int W, int n) {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=W; j++)
			dp[i][j] = (j < wt[i-1]) ? dp[i-1][j] : max(dp[i-1][j], val[i-1]+dp[i][j-wt[i-1]]);

	return dp[n][W];
}

int main(){
	int n, W;
	cin >> n;
	vector<int> wt(n), val(n);
	for(int i=0; i<n; i++) cin >> wt[i];
	for(int i=0; i<n; i++) cin >> val[i];
	cin >> W;

	// Applying Recursive method
	cout << ubKnapsackRecursive(wt, val, W, n) << endl;

	// Applying Memoized method
	vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
	cout << ubKnapsackMemoized(dp, wt, val, W, n) << endl;

	// Applying Dp Method
	vector<vector<int>> dp1(n+1, vector<int>(W+1));
	cout << ubKnapsackDp(dp1, wt, val, W, n) << endl;

	return 0;
}