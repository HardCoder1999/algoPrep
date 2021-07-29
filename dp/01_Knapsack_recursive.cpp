#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &val, vector<int> &wt, int W, int n) {
	return (W == 0 or n == 0) ? 0 : max(val[n-1] + knapsack(val, wt, W-wt[n-1], n-1), knapsack(val, wt, W, n-1));
}

int main(){
	int n, W;
	cin >> n;
	vector<int> wt(n), val(n);

	for(int i=0; i<n; i++) cin >> wt[i];
	for(int i=0; i<n; i++) cin >> val[i];

	cin >> W;

	cout << knapsack(val, wt, W, n) << endl;
	return 0;
}