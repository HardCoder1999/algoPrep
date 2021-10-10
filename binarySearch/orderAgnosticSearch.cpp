#include <bits/stdc++.h>

using namespace std;

int ascSearch(vector<int> &ar, int key, int n) {
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

int descSearch(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid;
	while(start <= end) {
		mid = start + (end-start)/2;
		if(ar[mid] == key)
			return mid;
		else if(ar[mid] < key)
			end = mid-1;
		else
			start = 1;
	}
	return -1;

}
int orderAgnosticSearch(vector<int> &ar, int key, int n) {
	if(ar.size() == 1){
		if(ar[0] == key)
			return 0;
		else
			return -1;
	}else{
		if(ar[0] < ar[1])
			return ascSearch(ar, key, n);
		else
			return descSearch(ar, key, n);
	}
}

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> ar(n);

	for(int i=0; i<n; i++) cin >> ar[i];

	cout << orderAgnosticSearch(ar, key, n) << endl;
}