#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long n;
		cin >> n;
		long long count = 0;
		for(int i=1; i<10; i++) {
			long long num = i;
			while(num <= n){
				count++;
				num = num*10 + i;
			}
		}
		cout << count << endl;
	}
}