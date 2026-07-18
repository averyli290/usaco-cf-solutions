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

/*
-1 or 0 to start
how many seq sum to 0?


5-9+

can only have one with a diff of -1

*/


const ll m = 1e9+7;
const ll MAXN = 2e5;

vll factorial;

ll inv(ll a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

long long C(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % m) % m;
}


void solve() {
    int n; cin >> n;

    vll a(n);

    map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll totmult = 1ll;
    for(auto [k,v] : mp) {
        ll temp = 0ll;
        for(ll val = 0; val <= v; val+=2) {
            temp += C(v, val);
        }
        totmult *= temp;
        totmult %= m;
    }

    ll tot=0ll;
    tot += totmult;
    tot %= m;

    for(int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 1 && mp[-1] > 0) {
            tot += totmult;
            tot %= m;
        }
    }
    cout << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.resize(MAXN + 1);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
