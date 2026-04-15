/*
Problem link: https://codeforces.com/contest/2171/problem/G
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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;
const long long MOD = 1e6+3;

vll factorial;
vll inv;

ll factmod(ll n, ll p) {
    vector<ll> f(p);
    f[0] = 1;
    for (ll i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    ll res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    bool can_div = true;
    for(int i = 0; i < n; i++) {
        if (b[i] / 2 < a[i]) {
            can_div = false;
            break;
        }
    }
    ll ans = 1;
    int x = 0;
    while(can_div) {
        int num_odd = 0;
        for(int i = 0; i < n; i++) {
            if (b[i] % 2 == 1) {
                num_odd++;
                b[i]--;
            }
            b[i] >>= 1;
            if (b[i] < a[i] * 2) can_div = false;
        }
        ans = (ans * factorial[num_odd]) % MOD;
        x += num_odd;
        x++; // div by 2
    }
    ll totdiff = 0LL;
    for(int i = 0; i < n; i++) {
        int diff = b[i] - a[i];
        totdiff += (ll) diff;
        ans = (ans * inv[factorial[diff]]) % MOD;
    }
    if (totdiff >= MOD) {
        ans = 0LL;
    } else {
        ans = (ans * factmod(totdiff, MOD)) % MOD;
    }
    x += totdiff;
    cout << x << " " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    factorial.resize(1E6+4, 0);
    factorial[1] = 1LL;
    factorial[0] = 1LL;
    for (int i = 2; i < 1E6+4; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    inv.resize(MOD);
    inv[1] = 1;
    for(int a = 2; a < MOD; ++a) {
        inv[a] = MOD - (long long)(MOD/a) * inv[MOD%a] % MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
