#include <bits/stdc++.h>

using namespace std;

int ceil(vector<int> &ar, int key, int n) {
	int start=0, end=n-1, mid;
	if(key < ar[start]) return start;
	while(start < end) {
		mid = start + (end-start)/2;
		if(ar[mid] == key)
			return mid;
		if(ar[mid]>key and ar[mid-1]<key)
			return mid;

		if(ar[mid] < key)
			start = mid+1;
		else
			end = mid-1;
	}
	return n;
}



int main() {
	int turt = 
	return 0;
}

