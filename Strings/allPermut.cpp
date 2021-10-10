#include <bits/stdc++.h>

using namespace std;

void allPermut(string s, string result, int index, int n) {
	if(index == n) return;
	allPermut(s, result, index+1, n);
	allPermut(s, result+s[index], index+1, n);
	cout << result << endl;

}

int main() {
	string s;
	cin >> s;

	allPermut(s, "", 0, s.length());
	return 0;
}