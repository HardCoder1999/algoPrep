#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int key) {
	int mid;
	while(start <= end) {
		mid = start + (end-start)/2;
		if(arr[mid] == key)
			return mid;
		if(mid > start and arr[mid-1] == key)
			return mid-1;
		if(mid < end and arr[mid+1] == key)
			return mid+1;

		if(arr[mid] > key)
			end = mid-2;
		else
			start = mid+2;
	}
	return -1;
}

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> arr(n);

	cout << binarySearch(arr, 0, n-1, key) << endl;
}