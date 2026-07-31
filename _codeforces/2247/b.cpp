/*
Problem link: https://codeforces.com/contest/2247/problem/B
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
https://www.youtube.com/watch?v=9qN9EF-6IcI
*/

void solve() {
    ll n, m, k; cin >> n >> k >> m;
    if (k > m) {
        cout << "NO" << endl;
        return;
    }
    vll a(n);
    for(int i = 0; i < k - 1; i++) {
        a[i] = 1;
    }
    a[k - 1] = m - (k - 1);
    for(int i = k; i < n; i++) {
        a[i] = 1;
    }
    cout << "YES" << endl;
    for(ll v : a) cout << v << " ";
    cout << endl;
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