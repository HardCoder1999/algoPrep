#include <bits/stdc++.h>

using namespace std;

int countSubsetRecursive(vector<int> &nos, int s, int n) {
	if(s == 0) return 1;
	if(n == 0) return 0;

	return countSubsetRecursive(nos, s, n-1) + countSubsetRecursive(nos, s-nos[n-1], n-1);
}

int countSubsetMemoized(vector<vector<int>> &dp, vector<int> &nos, int sum, int n) {
	if(sum == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][sum] != -1) return dp[n][sum];

	dp[n][sum] = (sum < nos[n-1]) ? countSubsetMemoized(dp, nos, sum, n-1) : countSubsetMemoized(dp, nos, sum, n-1) + countSubsetMemoized(dp, nos, sum-nos[n-1], n-1);
	return dp[n][sum];
}

int countSubsetDp(vector<vector<int>> &dp, vector<int> &nos, int sum, int n) {
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=sum; j++)
			dp[i][j] = (j < nos[i-1]) ? dp[i-1][j] : dp[i-1][j] + dp[i-1][j-nos[i-1]];

	return dp[n][sum];
}

int main(){
	int n, sum;
	cin >> n;
	vector<int> nos(n);
	for(int i=0; i<n; i++) cin >> nos[i];
	cin >> sum;
	
	// Apply Recursive
	cout << countSubsetRecursive(nos, sum, n) << endl;

	// Apply memoized technique
	vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	cout << countSubsetMemoized(dp, nos, sum, n) << endl;

	// Apply Dp technique
	vector<vector<int>> dp1(n+1, vector<int>(sum+1));
	cout << countSubsetDp(dp1, nos, sum, n) << endl; 

	return 0;
}