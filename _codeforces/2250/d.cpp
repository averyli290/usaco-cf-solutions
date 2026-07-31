/*
Problem link: https://codeforces.com/contest/2250/problem/D
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

find if go up to peak then down

force element on edges

*/

vll fact;
const ll M = 998244353ll;

void solve() {
    int n; cin >> n;
    vi a(n - 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int v : a) {
        if (v == n) {
            cout << 0 << endl; return;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact.assign(1e6+1,1);
    for(ll i = 1; i <= (ll) 1e6; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
