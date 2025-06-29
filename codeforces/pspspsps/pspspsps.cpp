/*
Avery Li
XX/XX/XXXX
Problem link: https://codeforces.com/contest/2049/problem/B
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;

void solve() {
    cin >> n >> s;

    if (s[0] == 's') s[0] = '.';
    if (s[n-1] == 'p') s[n-1] = '.';
    //cout << s << endl;
    if (count(s.begin(), s.end(), 's') > 0 && count(s.begin(), s.end(), 'p') > 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
