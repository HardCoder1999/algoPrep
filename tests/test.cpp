#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length(), index=0;
    for(int i=n-1; i>=0; i--) {
        if(s[i] == '-' or s[i] == '+' or s[i] == '/' or s[i] == '*' or s[i] == '%'){
            index=i;
            break;
        }
    }
    cout << index << endl;
    return 0;
}