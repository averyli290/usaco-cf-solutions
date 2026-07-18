/*
Problem link: https://codeforces.com/contest/2241/problem/B
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

// cf why did u go down at the start of my virtual :(

void solve() {
    ll x; cin >> x;
    ll y = x;
    ll z = 1ll;
    while(y > 0) {
        z *= 10;
        y /= 10;
    }
    z++;
    cout << z << endl;
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