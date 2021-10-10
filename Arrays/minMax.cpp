#include <bits/stdc++.h>

using namespace std;

pair<int, int> p;

pair<int, int> getMinMax(vector<int> &ar, int low, int high) {

	p.first = ar[low];
	p.second = ar[low];

	if(low == high) {
		p.first = ar[low];
		p.second = ar[low];
		return p;
	}
}

int main() {

	return 0;
}