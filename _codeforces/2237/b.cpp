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
    int n; cin >> n;
    vi a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i =0 ; i < n; i++) {
        cin >> b[i];
    }
    vi c = a;
    sort(all(c));
    for(int i = 0; i < n; i++) {
        if (c[i] > b[i]) {
            cout << -1 << endl;
            return;
        }
    }

    ll ans = 0ll;
    // debug(n);
    for(int i = 0; i < n; i++) {
        if (a[i] <= b[i]) continue;
        // debug(i);
        int minidx = -1;
        // for(int x : a) {
        //     cout << x << " ";
        // }
        // cout << endl;
        for(int j = i; j < n; j++) {
            if (a[j] <= b[i]) {
                minidx = j;
                break;
            }
        }
        // debug(minval);
        // debug(minidx);

        for(int j = minidx; j > i; j--) {
            swap(a[j], a[j - 1]);
            ans++;
        }
        // debug(ans);
    }
    cout << ans << endl;

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
