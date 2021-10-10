#include <bits/stdc++.h>

using namespace std;

int numberOfTimesArrayIsRotated(vector<int> &ar, int n) {
	int start=0, end=n-1, mid, prev, next;
	while(start <= end) {
		mid = start + (end-start)/2;
		prev = (mid-1+n)%n;
		next = (mid+1)%n;

		if(ar[mid] <= ar[prev] and ar[mid] <= ar[next])
			return mid;
		else if(ar[end] > ar[mid])
			end = mid-1;
		else
			start = mid+1;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for(int i=0; i<n; i++) cin >> ar[i];

	cout << numberOfTimesArrayIsRotated(ar, n) << endl;
}