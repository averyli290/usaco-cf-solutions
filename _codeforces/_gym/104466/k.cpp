/*
Problem link: https://codeforces.com/gym/104466/problem/K
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
*/

const ll M = 1e9+7;
const int MAXN = 1e6+1;


ll inv(ll a) {
  return a <= 1 ? a : M - (long long)(M/a) * inv(M % a) % M;
}


void solve() {
    vll f(MAXN, 1);
    for(ll i = 2; i < MAXN; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= M;
    }

    int n, h; cin >> n >> h;
    vll a(h);
    vll pref(h + 1, 0ll);
    ll sum = 0ll;
    for(int i = 0; i < h; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll rem = n - sum;

    vll dp(h);

    ll tot = 0ll;
    
    for(int i = 0; i < h; i++) {
        ll curtot = 0ll;
        ll cur = a[i];
    }

    cout << (((f[n] - tot) % M) + 2 * M) % M << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
