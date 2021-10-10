#include <bits/stdc++.h>

using namespace std;

int firstOccurence(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid, result=-1;
	while(start <= end) {
		mid = start+(end-start)/2;
		if(ar[mid] == key){
			result = mid;
			end = mid-1;
		} else if(ar[mid] < key)
			start = mid+1;
		else
			end = mid-1;
	}
	return result;
}

int lastOccurence(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid, result=-1;
	while(start <= end) {
		mid = start + (end-start)/2;
		if(ar[mid] == key){
			result = mid;
			start = mid+1;
		} else if(ar[mid] < key)
			start = mid+1;
		else
			end = mid-1;
	}
	return result;
}

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> ar(n);
	for(int i=0; i<n; i++) cin >> ar[i];

	cout << "First occurence is at index : " << firstOccurence(ar, key, n) << endl;
	cout << "Last occurence is at index : " << lastOccurence(ar, key, n) << endl;
	return 0;
}