/*
Problem link: https://codeforces.com/contest/2053/problem/D
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
const long long M = 998244353;

ll inv(ll a) {
  return a <= 1 ? a : M - (long long)(M/a) * inv(M % a) % M;
}

void solve() {
    int n, q; cin >> n >> q;
    // vector<pair<ll, int>> ta(n), tb(n);
    vll oa(n), ob(n);
    for(int i = 0; i < n; i++) {
        // ll x; cin >> x;
        // ta[i] = {x, i};
        cin >> oa[i];
    }
    for(int i = 0; i < n; i++) {
        // ll x; cin >> x;
        // tb[i] = {x, i};
        cin >> ob[i];
    }
    // sort(all(ta));
    // sort(all(tb));
    // vector<int> mpa(n), mpb(n), mpai(n), mpbi(n);
    // vll a(n),b(n);
    vll a = oa;
    vll b = ob;
    // for(int i = 0; i < n; i++) {
    //     a[i] = ta[i].first;
    //     b[i] = tb[i].first;
    //     mpa[ta[i].second] = i;
    //     mpb[tb[i].second] = i;
    //     mpai[i] = ta[i].second;
    //     mpbi[i] = tb[i].second;
    // }
    ll ans = 1ll;
    sort(all(a));
    sort(all(b));
    for(int i = 0; i < n; i++) {
        ans *= min(a[i], b[i]);
        ans %= M;
    }
    cout << ans << " ";
    while(q--) {
        int o, x; cin >> o >> x;
        x--;
        if (o == 1) {   // modify a
            int val = oa[x];
            auto ptr = lower_bound(all(a), val + 1) - 1;
            int idx = ptr - a.begin();
            ans *= inv(min(a[idx], b[idx]));
            ans %= M;
            a[idx]++;
            oa[x]++;
            ans *= min(a[idx], b[idx]);
            ans %= M;
            // int targidx = mpa[x];


            // ans *= inv(min(a[targidx], b[targidx]));

            // a[targidx]++;
            // if (targidx < n - 1) {
            //     if (a[targidx] > a[targidx + 1]) {
            //         ans *= inv(min(a[targidx+1], b[targidx+1]));
            //         int prev = mpai[targidx + 1];
            //         swap(a[targidx], a[targidx+1]);
            //         mpa[x] = targidx + 1;
            //         mpa[prev] = targidx;
            //         mpai[targidx] = prev;
            //         mpai[targidx+1] = x;
            //         ans *= min(a[targidx+1], b[targidx+1]);
            //         ans %= M;
            //     }
            // }
            // ans *= min(a[targidx], b[targidx]);
            // ans %= M;
        } else {
            int val = ob[x];
            auto ptr = lower_bound(all(b), val + 1) - 1;
            int idx = ptr - b.begin();
            ans *= inv(min(a[idx], b[idx]));
            ans %= M;
            b[idx]++;
            ob[x]++;
            ans *= min(a[idx], b[idx]);
            ans %= M;
            // int targidx = mpb[x];

            // ans *= inv(min(a[targidx], b[targidx]));

            // b[targidx]++;
            // if (targidx < n - 1) {
            //     if (b[targidx] > b[targidx + 1]) {
            //         ans *= inv(min(a[targidx+1], b[targidx+1]));
            //         int prev = mpbi[targidx + 1];
            //         swap(b[targidx], b[targidx+1]);
            //         mpb[x] = targidx + 1;
            //         mpb[prev] = targidx;
            //         mpbi[targidx] = prev;
            //         mpbi[targidx+1] = x;
            //         ans *= min(a[targidx+1], b[targidx+1]);
            //         ans %= M;
            //     }
            // }
            // ans *= min(a[targidx], b[targidx]);
        }
        cout << ans << " ";
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
