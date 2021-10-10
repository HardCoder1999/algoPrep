#include <bits/stdc++.h>

using namespace std;

int findElementInSortedRotatedArray(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid, prev, next;
	while(start <= end) {
		mid = start + (end-start)/2;
		// prev = (mid-1+n)%n;
		// next = (mid+1)%n;

		if(ar[mid] == key)
			return mid;
		else if(ar[mid] > ar[start] and (key < ar[mid] and key >= ar[start]))
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> ar(n);
	for(int i=0; i<n; i++) cin >> ar[i];

	cout << findElementInSortedRotatedArray(ar, key, n) <<endl;
}