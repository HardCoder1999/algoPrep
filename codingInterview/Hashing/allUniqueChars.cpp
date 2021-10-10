#include <bits/stdc++.h>

using namespace std;

// Using Hashing
bool isUnique(string s) {
	unordered_map<char, int> dict;
	for(auto i: s){
		if(dict.find(i) == dict.end())
			dict[i]++;
		else{
			return false;
		}
	}
	return true;
}

// Using sorting
bool checkIfUnique(string s, int n) {
	if(s.length() <= 1) return true;
	sort(s.begin(), s.end());

	for(int i=0; i<n-1; i++)
		if(s[i] == s[i+1])
			return false;

	return true;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	

	checkIfUnique(s, n)? cout << "Unique" << endl : cout << "Not Unique" << endl;

	return 0;
}