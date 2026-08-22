/*
Problem link: https://codeforces.com/contest/2254/problem/D
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

void solve() {
    int n; cin >> n;
    vll b(n);
    map<ll, int> mp;
    set<ll> a;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]]++;
        a.insert(b[i]);
    }
    vll c(all(a));
    map<ll, ll> mpans;
    ll prevval=0ll;
    // if (sz(c) == 1 && c[0] != 0) {
    //     cout << -1 << endl;
    //     return;
    // }
    for(int i = 1; i < sz(c); i++) {
        ll ct = mp[c[i - 1]];
        ll valdiff = c[i] - c[i - 1];
        if (valdiff % ct != 0) {
            cout << -1 << endl;
            return;
        }
        ll la = valdiff / ct;
        if (la <= prevval) {
            cout << -1 << endl;
            return;
        }
        mpans[c[i - 1]] = la;
        prevval = la;
    }
    mpans[c.back()] = prevval + 1;

    int ctr = 0;
    ll cursum = 0ll;
    for(auto [k, v] : mpans) {
        // debug(cursum);
        if (c[ctr] != cursum) {
            cout << -1 << endl;
            return;
        }
        ctr++;
        cursum += v * mp[k];
    }

    for(int i = 0; i < n; i++) {
        cout << mpans[b[i]] << " ";
    }
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
