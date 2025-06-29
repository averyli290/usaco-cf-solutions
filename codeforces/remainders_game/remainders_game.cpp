/*
Avery Li
5/2/2025
Problem link: https://codeforces.com/problemset/problem/687/B
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;


/*
CRT can uniquely determine answer up to lcm(c1, c2, c3, ..., cn)
if lcm % k == 0, can create an onto mapping from Z(lcm)/Z -> Zk/Z because then
mod lcm is more specific than mod k, so can find any x mod k using x mod lcm.

suffices to now check lcm % k == 0

*/

void solve() {
    int n;
    ll k; cin >> n >> k;

    int a;
    ll cur = 1;
    for(int i = 0; i < n; i++) {
        cin >> a;
        cur = cur / gcd(cur, a) * a;
        cur %= k;       // prevent overflow, multiplication and divison still hold under mod
    }
    if (cur % k == 0) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
