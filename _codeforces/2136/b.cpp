/*
Problem link: https://codeforces.com/contest/2136/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;


void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi p(n);
    int cur = 1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            p[i] = cur;
            cur++;
        }
    }
    for(int i = 0; i < n; i++) {
        if (s[i] == '0') {
            p[i] = cur;
            cur++;
        }
    }
    set<int> w;
    for(int i = 0; i < k; i++) {
        w.insert(p[i]);
    }
    for (auto v : p) {
        cout << v << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1' && *max_element(all(w)) == p[i]) {
            cout << "NO" << endl;
            return;
        }
        if (i + k < n) {
            w.insert(p[i + k]);
        }
        if (i - k >= 0) {
            w.erase(p[i - k]);
        }
    }
    cout << "YES" << endl;
    // for (auto v : p) {
        // cout << v << " ";
    // }
    // cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
