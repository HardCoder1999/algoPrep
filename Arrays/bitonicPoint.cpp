#include <bits/stdc++.h>

using namespace std;

int bitonicPoint(vector<int> &ar, int n) {
	int l=0, r=n-1;
	while(l <= r) {
		int mid = l+(r-l)/2;

		if(ar[mid] > ar[mid-1] and ar[mid] > ar[mid+1])
			return ar[mid];
		else if(ar[mid] > ar[mid+1])
			r = mid-1;
		else if(ar[mid] < ar[mid+1])
			l = mid+1;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> ar(n);

	for(int i=0; i<n; i++) cin >> ar[i];

	cout << bitonicPoint(ar, n) << endl;
	return 0;
}