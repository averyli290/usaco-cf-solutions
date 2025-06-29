/*
Avery Li
4/30/2025
Problem link: https://codeforces.com/problemset/problem/1328/C
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    string x; cin >> x;
    string a="";
    string b="";
    bool encountered_one = false;
    for(int i = 0; i < n; i++) {
        if (x[i] == '0') {
            a += '0';
            b += '0';
        }
        else if (!encountered_one) {
            if (x[i] == '1') {
                a += '1';
                b += '0';
                encountered_one = true;
            } else if (x[i] == '2'){
                a += '1';
                b += '1';
            }
        }
        else {
            if (x[i] == '1') {
                a += '0';
                b += '1';
            } else {
                a += '0';
                b += '2';
            }
        }
    }
    cout << a << endl << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
