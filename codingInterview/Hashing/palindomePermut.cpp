#include <bits/stdc++.h>

using namespace std;

// check by  hashing
bool isPermut(string s) {
	unordered_map<char, int> dict;
	for(auto i: s) dict[i]++;

	int countOdd = 0;
	for(auto& itr: dict)
		if(itr.second%2)
			countOdd++;

	return countOdd <= 1? true : false; 
}

// check by sorting
bool checkPermut(string s) {
	sort(s.begin(), s.end());
	int index=0, n=s.length(), countOdd=0;
	while(index<n and index+1<n) {
		if(s[index]==s[index+1])
			index+=2;
		else{
			index+=1;
			countOdd++;
		}
	}
	return countOdd <= 1 ? true : false;
}


int main() {
	string s;
	cin >> s;

	cout << checkPermut(s) << endl;
}