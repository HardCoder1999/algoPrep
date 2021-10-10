#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid;
	while(start <= end) {
		mid = start + (end-start)/2;
		if(ar[mid] == key)
			return mid;
		else if(ar[mid] < key)
			start = mid+1;
		else
			end = mid-1;
	}
	return -1;
} 

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> ar(n);

	for(int i=0; i<n; i++) cin >> ar[i];

	cout << binarySearch(ar, key, n) << endl;
}