#include <bits/stdc++.h>

using namespace std;

string reverseVowel(string s) {
int start=0, end=s.length()-1, startFlag, endFlag;
	    while(start < end) {
		    startFlag = 0;
		    endFlag = 0;
		    if(s[start] == 'a' or s[start] == 'e' or s[start] == 'i' or s[start] == 'o' or s[start] == 'u' or s[start] == 'A' or s[start] == 'E' or s[start] == 'I' or s[start] == 'O' or s[start] == 'U')
			    startFlag = 1;
		    else
			    start++;
		    if(s[end] == 'a' or s[end] == 'e' or s[end] == 'i' or s[end] == 'o' or s[end] == 'u' or s[end] == 'A' or s[end] == 'E' or s[end] == 'I' or s[end] == 'O' or s[end] == 'U')
			    endFlag = 1;
		    else
			    end--;

		    if(startFlag == 1 and endFlag == 1) {
			    char temp = s[start];
			    s[start] = s[end];
			    s[end] = temp;
			    end--;
			    start++;
		    }
	    }
	    return s;
}

int main() {
	string s;
	cin >> s;
	cout << reverseVowel(s) << endl;
	return 0;
}