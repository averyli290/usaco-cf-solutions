/*
Problem link: https://codeforces.com/contest/2039/problem/D
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

vll primes;

void solve() {
    int n, m; cin >> n >> m;
    vi a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(all(a));
    vll ans(n + 1);
    vector<bool> ASS(n + 1, false);
    ans[1] = m - 1;
    for(int i = 2; i <= n; i++) {
        if (!ASS[i]) {
            ans[i] = m - 2;
            ASS[i] = true;
        }
        for(int p : primes) {
            if (i * p > n) break;
            if (!ASS[i * p]) {
                // cout << "HERE" << endl;
                // debug(ans[i] - 1);
                ans[i * p] = ans[i] - 1;
                ASS[i * p] = true;
            }
        }
    }
    vi sol(n);
    // for(int i = 1; i <= n; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= n; i++) {
        if (ans[i] < 0) {
            cout << -1 << endl;
            return;
        }
        sol[i - 1] = a[ans[i]];
    }
    for(int v : sol) cout << v << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAXN = 3e5;
    vector<bool> sieve(MAXN + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i * i <= MAXN; i++) {
        if (sieve[i]) {
            for(int j = i + i; j <= MAXN; j += i) {
                sieve[j] = false;
            }
        }
    }
    for(int i=0;i<=MAXN;i++) if (sieve[i]) primes.push_back(i);
    // for (int p : primes) {
    //     cout << p << " ";
    // }
    // cout << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
