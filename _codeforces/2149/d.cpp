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


ll calc(vll a) {
    if (sz(a) == 0) { return 0; }

    vll b;
    for(int i = 0; i < sz(a); i++) {
        b.push_back(a[i] - (ll) i);
    }
    sort(all(b));
    ll med = b[sz(b) / 2];
    ll ans = 0;
    for(int i = 0; i < sz(b); i++) {
        ans += abs(((ll) b[i]) - med);
    }
    return ans;
}

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vll a;
    vll b;
    for(ll i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    cout << min(calc(a), calc(b)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}