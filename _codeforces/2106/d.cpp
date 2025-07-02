/*
Problem link: https://codeforces.com/contest/2106/problem/D
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


void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    vi b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int j = 0;
    vi pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        if (j < m && a[i] >= b[j]) j++;
        pref[i] = j;
    }
    pref[n] = pref[n - 1];

    vi suff(n + 2, 0);
    j = 0;
    for(int i = n - 1; i >= 0; i--) {
        if (j < m && a[i] >= b[m - 1 - j]) j++;
        suff[i] = j;
    }

    // for(int i : pref) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(int i : suff) {
    //     cout << i << " ";
    // }
    // cout << endl;

    if (suff[0] == m || pref[n - 1] == m) {
        cout << 0 << endl;
        return;
    }

    int ans = -1;
    int l = -1;
    int h = *max_element(all(b)) + 1;
    while (h - l > 1) {
        int mid = (h + l) / 2;
        // cout << l << " " << mid << " " << h << endl;
        
        bool ok = false;
        for(int i = -1; i <= n; i++) {
            int v1 = (i == -1) ? 0 : pref[i];
            // cout << "i + 1: " << i + 1 << endl;
            if (v1 + suff[i + 1] == m) {
            // cout << "OK " << i << " " << pref[i] << " " << suff[i] << endl;
                ok = true;
                break;
            } else if (v1 + suff[i + 1] == m - 1 && mid >= b[v1]) {
                // cout << i + 1 << " " << suff[i + 1] << endl;
                // cout << "OK HERE " << i << " " << suff[i + 1] << " " << endl;
                // cout << "OK " << i << " " << pref[i] << " " << suff[i] << endl;
                ok = true;
                break;
            }
        }
        if (ok) {
            h = mid;
            ans = mid;
        } else {
            l = mid;
        }
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