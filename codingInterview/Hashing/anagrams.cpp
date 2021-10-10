#include <bits/stdc++.h>

using namespace std;

// using sorting
bool checkAnagrams(string s1, string s2) {
	if(s1.length() != s2.length()) return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	for(int i=0; i<s1.length(); i++)
		if(s1[i] != s2[i])
			return false;

	return true;
}

// using hashing
bool isAnagrams(string s1, string s2) {
	if(s1.length() != s2.length()) return false;
	unordered_map<char, int> dict;

	for(auto i: s1) dict[i]++;
	for(auto i: s2) {
		if(dict.find(i) == dict.end() or dict[i] <= 0) return false;
		else dict[i]--;
	}
	return true;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	checkAnagrams(s1, s2)? cout << "Anagrams" << endl : cout << "No Anagrams" << endl;
	return 0;
}