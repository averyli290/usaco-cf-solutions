/*
Problem link: https://codeforces.com/contest/2148/problem/G
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


set<int> factors(int x) {
    set<int> retval;
    for(int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            retval.insert(i);
        }
    }
    return retval;
}

void solve() {
    int n; cin >> n;
    int a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int gg = a[0];
    for(int i = 0; i < n; i++) gg = gcd(gg, a[i]);
    for(int i = 0; i < n; i++) a[i] /= gg;

    for(int i = 0; i < n; i++) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
