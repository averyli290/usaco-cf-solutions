
/*
Problem link: https://codeforces.com/contest/2234/problem/D
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
const long long M = 1E9+7;

/*
find valid splitting point, iterate from left to right in range defined by recursion
partition left and right sides using choose with a total number of right - left + 1 elements 
*/

ll rec(vll a, ll& ct) {
    if (sz(a) == 0) return 1ll;
    // for(ll x : a) {
    //     cout << x << " ";
    // }
    // cout << endl;
    map<ll, ll> freq;
    ll tot = 0ll;
    ll maxval1 = 0ll;
    ll maxval2 = 0ll;
    for(int i = 0; i < sz(a); i++) {
        freq[a[i]]++;
        if (a[i] > maxval2) maxval2 = a[i];
        if (maxval2 > maxval1) swap(maxval1, maxval2);
        tot += a[i];
    }
    vector<vll> vecs;
    vecs.push_back(vll{});
    for(int i = 0; i < sz(a); i++) {
        if (a[i] == maxval1) vecs.push_back(vll{});
        else vecs[sz(vecs) - 1].push_back(a[i]);
    }
    ll ans = ct - sz(freq) + 1;
    if (ct == sz(a)) ans = 1ll;
    // debug(ct - sz(freq) + 1);
    // ct -= freq[maxval1];
    ct -= 1ll;
    // debug(freq[maxval2]);
    // if (freq[maxval2] >= 1) {
    //     for(ll i = 0ll; i < freq[maxval2]; i++) {
    //         ans = (ans * (ct - i)) % M;
    //     }
    // }

    // ll ans = 1ll;
    // ans = ans * factorial[freq[maxval2]] % M;
    for(int i = 0; i < sz(vecs); i++) {
        // if (ct > 0) ans = ans * ct % M;
        // debug(ans);
        // debug(ct);
        ans = (ans * rec(vecs[i], ct)) % M;
    }
    // debug(ans);
    return ans;
}

void solve() {
    ll n; cin >> n;
    vll a(n);
    ll maxval = 0ll;
    ll tot = 0ll;
    map<ll, ll> freq;
    bool good = true;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        maxval = max(maxval, a[i]);
        tot += a[i];
        if (a[i] > (i + 1) * (n - i)) good = false;
    }
    if (tot != n * (n + 1)/2 || freq[maxval] > 1 || !good) {
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if (a[i] == maxval) {
            if (a[i] != (i + 1) * (n - i)) {
                cout << 0 << endl;
                return;
            }
            break;
        }
    }

    // ll ans = 1ll;
    // for(auto[k, v] : freq) {
    //     ans = (ans * factorial[v]) % M;
    // }

    // cout << ans << endl;
    ll N = n;
    cout << rec(a, N) << endl;
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