#include <bits/stdc++.h>

using namespace std;

int rodCuttingRecursive(vector<int> &len, vector<int> &prices, int l, int n) {
	if(n == 0 or l == 0) return 0;

	return (l < len[n-1]) ? rodCuttingRecursive(len, prices, l, n-1) : 
	max(rodCuttingRecursive(len, prices, l, n-1), prices[n-1] + rodCuttingRecursive(len, prices, l-len[n-1], n));
}

int rodCuttingMemoized(vector<vector<int>> &dp, vector<int> &len, vector<int> &prices, int l, int n) {
	if(n == 0 or l == 0) return 0;

	if(dp[n][l] != -1) return dp[n][l];

	dp[n][l] = (l < len[n-1]) ? rodCuttingMemoized(dp, len, prices, l, n-1) : 
	max(rodCuttingMemoized(dp, len, prices, l, n-1), prices[n-1] + rodCuttingMemoized(dp, len, prices, l-len[n-1], n));

	return dp[n][l];
}

int rodCuttingDp(vector<vector<int>> &dp, vector<int> &len, vector<int> &prices, int l, int n) {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=l; j++)
			dp[i][j] = (j < len[i-1]) ? dp[i-1][j] : max(dp[i-1][j], prices[i-1]+dp[i][j-len[i-1]]);

	return dp[n][l];
}

int main(){
	int n, l;
	cin >> n;
	vector<int> len(n), prices(n);

	for(int i=0; i<n; i++) cin >> len[i];
	for(int i=0; i<n; i++) cin >> prices[i];

	cin >> l;
	
	// Apply Recursive method
	cout << rodCuttingRecursive(len, prices, l, n) << endl;

	// Apply Memoized method
	vector<vector<int>> dp(n+1, vector<int>(l+1, -1));
	cout << rodCuttingMemoized(dp, len, prices, l, n) << endl;

	// Apply Dp Method
	vector<vector<int>> dp1(n+1, vector<int>(l+1));
	cout << rodCuttingDp(dp1, len, prices, l, n) << endl;
	return 0;
}