/*
Avery Li
2/27/2025
Problem link: https://codeforces.com/contest/2070/problem/B
*/

#include <iostream>
#include <bits/stdc++.h>
#include <string>
typedef long long ll;


using namespace std;

void solve() {
    ll n, x, k;
    string s;
    cin >> n >> x >> k;
    cin >> s;

    int index = 0;
    while (index < n && k > 0 && x != 0) {
        if (s[index] == 'R') {
            x++;
        } else {
            x--;
        }
        index++;
        k--;
    }
    if (x != 0) {
        cout << 0 << endl;
        return;
    }

    if (k == 0) {
        cout << 1 << endl;
        return;
    }

    index = 0;
    if (s[index] == 'R') {
        x++;
    } else {
        x--;
    }
    index++;
    k--;
    while (index < n && k > 0 && x != 0) {
        if (s[index] == 'R') {
            x++;
        } else {
            x--;
        }
        index++;
        k--;
    }
    if (x != 0) {
        cout << 1 << endl;
        return;
    }
    cout << 2 + k / (index) << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
