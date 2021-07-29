#include <bits/stdc++.h>

using namespace std;

int minSubsetSumDiffRecursive(vector<int> &ar, int sum, int n, int sumCalculated) {
	if(n == 0) return sum - 2*sumCalculated;
	else return min(minSubsetSumDiffRecursive(ar, sum, n-1, sumCalculated+ar[n-1]), minSubsetSumDiffRecursive(ar, sum, n-1, sumCalculated));
}

int minSubsetSumDiffMemoized(vector<vector<int>> &dp, vector<int> &ar, int sum, int n, int sumCalculated) {
	if(n == 0) return abs(s-2*sumCalculated);

	if(dp[n][sum] != -1) return dp[n][sum];

	dp[n][sum] = min(minSubsetSumDiffMemoized(dp, ar, n-1, sum, sumCalculated), minSubsetSumDiffMemoized(dp, ar, n-1, sum, sumCalculated+ar[n-1]));
	return dp[n][sum];
}

int minSubsetSumDiffDp(vector<vector<int>> &dp, vector<int> &ar, int sum, int sumCalculated, int n) {
	
}

int main(){
	int n, sum=0;
	cin >> n;
	vector<int> ar(n);
	for(int i=0; i<n; i++) { cin >> ar[i]; sum += ar[i]; }


	return 0;
}