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


void solve() {
    ll n; cin >> n;
    function<bool(ll)> check = [&] (ll x) {
        string str = to_string(x);
        for(int i = 0; i < sz(str) / 2; i++) {
            if (str[i] != str[sz(str) - 1 - i]) return false;
        }
        return true;
    };
    for(ll a = 0ll; a <= 12000; a++) {
        if (check(a) && (n - a) % 12 == 0 && n - a >= 0) {
            cout << a << " " << n - a << endl;
            return;
        }
    }
    cout << -1 << endl;
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
