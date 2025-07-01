/*
Avery Li
4/27/2025
Problem link: https://codeforces.com/contest/2074/problem/C
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int x; cin >> x;

    int l = 0;
    int copy = x;
    while (copy > 0) {
        copy /= 2;
        l++;
    }
    // cout << endl;
    // cout << "l:" << l << endl;

    int ans = 1;
    bool works = false;
    //x /= 2;
    x &= ~(1 << (l - 1));
    cout << "x: "<< x << endl; 
    while (x > 1) {
        //cout << "x: " << x << endl;
        if (x % 2 == 0) {
            works = true;
        }
        if (!works) {
            ans <<= 1;
        }
        //cout << "ans: " << ans << endl;
        x /= 2;
    }
    if (works) {
        cout << ans << endl;
        return;
    }
    cout << -1 << endl;
    
    // 11110
    // 10001
    // 01111
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
