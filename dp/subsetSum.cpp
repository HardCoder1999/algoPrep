#include <bits/stdc++.h>

using namespace std;

bool subsetSumRecursive(vector<int> &nos, int sum, int n) {
	if(sum == 0) return true;
	if(n == 0) return false;

	return subsetSumRecursive(nos, sum, n-1) or subsetSumRecursive(nos, sum-nos[n-1], n-1); 
}

int subsetSumMemoized(vector<vector<int>> &dp, vector<int> &nos, int sum, int n) {
	if(sum == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][sum] != -1) return dp[n][sum];

	dp[n][sum] = (sum < nos[n-1]) ? subsetSumMemoized(dp, nos, sum, n-1) : subsetSumMemoized(dp, nos, sum, n-1) or subsetSumMemoized(dp, nos, sum-nos[n-1], n-1);

	return dp[n][sum];
}

int subsetSumDp(vector<vector<int>> &dp, vector<int> &nos, int sum, int n) {
	for(int i=0; i<=n; i++)
		dp[i][0] = 1;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=sum; j++)
			dp[i][j] = (j < nos[i-1]) ? dp[i-1][j] : dp[i-1][j-nos[i-1]] or dp[i-1][j];

	return dp[n][sum];
}

int main(){
	int n, sum;
	cin >> n;
	vector<int> nos(n);
	for(int i=0; i<n; i++) cin >> nos[i];
	cin >> sum;
	
	// Applying recursive procedure.
	cout << subsetSumRecursive(nos, sum, n) << endl;

	// Applying memoized procedure
	vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	cout << subsetSumMemoized(dp, nos, sum, n) << endl;

	// Applying top-down dp procedure
	vector<vector<int>> dp1(n+1, vector<int>(sum+1));
	cout << subsetSumDp(dp1, nos, sum, n) << endl;

	return 0;
}