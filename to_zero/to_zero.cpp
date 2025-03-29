/*
Avery Li
3/17/2025
Problem link: https://codeforces.com/contest/2075/problem/A
*/

#include <iostream>
//#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

void solve() {
    //cout << endl;
    int n, k;
    cin >> n >> k;
    if (n <= k) {
        cout << 1 << endl;
        return;
    }
    // subtract the largest odd number first
    int ans = 0;
    if (n % 2 == 1) {
        ans++;
        if (k % 2 == 1) {
            n -= k;
        } else {
            n -= k - 1;
        }
    }
    if (n > 0) {
        if (k % 2 == 1) {
            ans += n / (k - 1);
            //cout << "ans before " << ans << endl;
            n %= k - 1;
            //cout << "n before " << n << endl;
            ans += n > 0 ? 1 : 0;
            //cout << "ans after " << ans << endl;
        } else {
            ans += n / k;
            //cout << "ans before " << ans << endl;
            n %= k;
            //cout << "n before " << n << endl;
            ans += n > 0 ? 1 : 0;
            //cout << "ans after " << ans << endl;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
