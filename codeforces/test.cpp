// vector<int> parenting(vector<int> U, vector<char> val, vector<int> V){
// 	unordered_map<char, int> freq;
// 	vector<int> result(val.size());

// 	for(int i=0; i<val.size(); i++)
// 		freq[char[i]]++;


// }

#include <bits/stdc++.h>

using namespace std;

string KFrequency(string s, int K) {
	vector<int> result(26);

	for(auto i: s) result[i-'a']++;

	vector<int> x = result;

	sort(x.begin(), x.end(), greater<int>());

	int value = x[K];

	if(x[K] == 0) return "-1";

	for(int i=0; i<26; i++){
		if(result[i] == K){
			value = i;
			break;
		}
	}
	char chr = 'a'+value;
	string str = string(chr);
	return str;

}

int main(){
	int k;
	string s;
	cin >> s >> k;
	cout <<KFrequency(s, k) << endl;
	cout << char(97+1) << endl;
 	return 0;
}