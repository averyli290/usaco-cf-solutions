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
*/

void solve() {
    int n; cin >> n;
    vi a(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) mx = max(mx, 31 - __builtin_clz(a[i]));
    }
    vi ans;
    for(int i = mx; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            a[j] = abs(a[j] - (1 << i));
        }
        ans.push_back((1 << i));
    }

    bool f = false;
    for(int x : a) {
        if (x != 0) {
            f = true;
            break;
        }
    }
    if (f) {
        for(int j = 0; j < n; j++) {
            a[j] = abs(a[j] - 1);
        }
        ans.push_back(1);
    }
    for(int x : a) {
        if (x != 0) {
            cout << -1 << endl;
            return;
        }
    }

    cout << sz(ans) << endl;
    for (int x : ans) cout << x << " ";
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
