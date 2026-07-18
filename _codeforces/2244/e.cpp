/*
Problem link: https://codeforces.com/contest/2244/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*

001100
110010

1111
11111
10101

00111
01000
01010
*/

void solve() {
    int n, q; cin >> n >> q;
    vi pref(n + 1, 0);
    string s; cin >> s;
    vi a(n);
    for(int i = 0; i< n; i++) {
        a[i] = s[i] - '0';
    }
    for(int i = 1; i < n; i++) {
        int t = 0;
        if (a[i] == a[i - 1]) t++;
        pref[i] = pref[i - 1] + t;
        // debug(pref[i]);
    }
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        r--;
        l--;
        int ct = pref[r] - pref[l];
        if ((ct + 1) / 2 <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
