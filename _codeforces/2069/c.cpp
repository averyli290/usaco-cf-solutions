/*
Problem link: https://codeforces.com/contest/2069/problem/C
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
const long long MOD = 998244353;

/*
maintain current amount of ways to form front of subsequence
then, how does it change when encountering 1 or 2
what happens to total when encountering 3?
what cases should we exclude later?
*/

void solve() {
    int n; cin >> n;
    vi a(n);
    vll suff(n + 2, 0);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) {
        suff[i] = suff[i + 1];
        if (a[i - 1] == 3) suff[i]++;
    }

    suff[0] = suff[1];
    
    ll ans = 0;
    ll total = 0;   // the current number of ways to form front of subsequnce up to current idx
    for(int i = 0; i < n; i++) {
        if (a[i] == 1) total = (total + 1) % MOD;       // can start in another place
        else if (a[i] == 2) total = (total * 2) % MOD;  // can choose to include or exclude 2
        else ans = (ans + total) % MOD;                 // can close subsequence
    }

    // subtract off 1,3 subsequences
    for(int i = 0; i < n; i++) {
        if (a[i] == 1) ans = (ans - suff[i + 1]) % MOD;
    }
    cout << (ans + MOD) % MOD << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
