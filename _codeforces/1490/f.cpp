/*
Problem link: https://codeforces.com/problemset/problem/1490/F
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
    int n; cin >> n;
    vi a(n);
    map<int, int> m;
    for(int i = 0 ; i< n; i++)  {
        cin >> a[i];
        m[a[i]]++;
    }
    vi freq;
    for(auto &[k, v] : m) {
        freq.push_back(v);
    }
    sort(all(freq));
    n = sz(freq);
    int total = accumulate(all(freq), 0);
    int ans = total;
    for(int i = 0; i < n; i++) {   // make index i and below 0
        ans = min(ans, total - freq[i] * (n - i));
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
