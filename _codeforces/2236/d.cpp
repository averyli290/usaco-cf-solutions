/*
Problem link:
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


void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vi b;
    for(auto [k,v] : mp) b.push_back(k);
    for(int i = 0; i < sz(b) - 1; i++) {
        // always winning, can choose parity here after first selection
        // if choosing b[i] then b[i + 1] gives winning strategy away, can just choose b[i + 1]
        // first and use winning strategy from there by symmetry
        if (b[i + 1] - b[i] <= k) {
            cout << "YES" << endl;
            return;
        }
    }
    // gaps are too large
    for(auto [k, v] : mp) {
        if (v % 2 == 0){        // choose an elt to start with, cant cross gap
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
