#include <bits/stdc++.h>

using namespace std;

int countOfAnElement(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid, startIndex=-1, endIndex=-1;

	while(start <= end) {
		mid = start + (end-start)/2;
		if(ar[mid] == key){
			startIndex = mid;
			end = mid-1;
		} else if(ar[mid] < key)
			start = mid+1;
		else
			end = mid-1;
	}

	start=0, end=n-1;
	while(start <= end) {
		mid = start + (end-start)/2;
		if(ar[mid] == key) {
			endIndex = mid;
			start = mid+1;
		} else if(ar[mid] < key)
			start = mid+1;
		else
			end = mid-1;
	}

	return endIndex-startIndex+1;
}

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> ar(n);
	for(int i=0; i<n; i++) cin >> ar[i];

	cout << countOfAnElement(ar, key, n) << endl;
	return 0;
}