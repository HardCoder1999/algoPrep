#include <bits/stdc++.h>

using namespace std;

bool equalSumRecursive(vector<int> &nos, int sum, int n) {
	if(sum == 0) return true;
	if(n == 0) return false;

	return equalSumRecursive(nos, sum, n-1) or equalSumRecursive(nos, sum-nos[n-1], n-1);
}

int equalSumMemoized(vector<vector<int>> &dp, vector<int> &nos, int sum, int n) {
	if(sum == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][sum] != -1) return dp[n][sum];

	dp[n][sum] = (sum < nos[n-1]) ? equalSumMemoized(dp, nos, sum, n-1) : equalSumMemoized(dp, nos, sum, n-1) or equalSumMemoized(dp, nos, sum-nos[n-1], n-1);

	return dp[n][sum];
}

int equalSumDp(vector<vector<int>> &dp, vector<int> &nos, int sum, int n) {
	for(int i=0; i<n; i++) dp[i][0] = 1;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=sum; j++)
			dp[i][j] = (j < nos[i-1]) ? dp[i-1][j] : dp[i-1][j] or dp[i-1][j-nos[i-1]];

	return dp[n][sum];
}

int main(){
	int n, sum=0;
	cin >> n;
	vector<int> nos(n);
	for(int i=0; i<n; i++) { cin >> nos[i]; sum += nos[i]; }

	if(sum%2 != 0)
		cout << "Not Possible" << endl;
	else{
		// Applying recursive method
		cout << equalSumRecursive(nos, sum/2, n) << endl;

		// Applying Memoized method
		vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
		cout << equalSumDp(dp, nos, sum/2, n) << endl;

		// Applying Dp method
		vector<vector<int>> dp1(n+1, vector<int>(sum/2+1));
		cout << equalSumDp(dp1, nos, sum/2, n) << endl;
	}
	return 0;
}