/*
Problem link: https://codeforces.com/contest/2134/problem/B
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
    ll n, k; cin >> n >> k;
    // mod k - 1
    for(int i=0;i<n;i++) {
        ll a; cin >> a;
        cout << a + ((k + 1 + a) % (k + 1)) * k << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
