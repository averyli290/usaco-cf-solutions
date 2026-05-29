
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


void solve() {
    int n; cin >> n;
    vll a(n);
    bool has_odd = false;
    bool has_even = false;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x % 2 == 1) has_odd = true;
        else has_even = true;
        a[i] = x;
    }
    if (has_even && has_odd) cout << 2 << endl;
    else {
        ll cur = 2LL;
        while(true) {
            set<ll> s;
            for(int i = 0; i < n; i++) s.insert(a[i] % cur);
            if (sz(s) == 2) {
                cout << cur << endl;
                return;
            }
            cur *= 2;
        }
    }
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