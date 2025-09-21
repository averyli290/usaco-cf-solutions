/*
Problem link: https://codeforces.com/contest/2143/problem/B
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

/*
*/

void solve() {
    int n, k; cin >> n >> k;
    vll a(n);
    vi b(k);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    int idx = n - 1;
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        if (idx < 0) break;
        for(int j = 0; j < b[i] - 1; j++){
            if (idx < 0) break;
            ans += a[idx];
            idx--;
        }
        idx--;
    }
    while(idx >= 0) {
        ans += a[idx];
        idx--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
