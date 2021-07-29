#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &ar, int n) {
	int totalSum = (n*(n+1))/2;
	int actualSum = 0;

	for(int i=0; i<n-1; i++) actualSum += ar[i];
	return totalSum-actualSum;
}

int main(){
	int n;
	cin >> n;
	vector<int> ar(n-1);

	for(int i=0; i<n-1; i++) cin >> ar[i];
	cout << missingNumber(ar, n) << endl;
	return 0;
}