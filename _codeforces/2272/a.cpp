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
https://www.youtube.com/watch?v=zWoSvb1_vXQ
*/

int m(vi& b, int k) {
    int mx = 0;
    int n = sz(b);
    vector<bool> c(n, false);
    vi v(n);
    for(int i = 0; i < n; i++) {
        c[b[i]] = true;
        while(c[mx]) mx++;
        v[i] = mx;
    }
    sort(all(v));
    reverse(all(v));
    return v[k - 1];
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = m(a, k);
    bool changed = false;
    pii best;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            int temp = m(a, k);
            if (temp > mx) {
                mx = temp;
                best = {i + 1, j + 1};
                changed = true;
            }
            swap(a[i], a[j]);
        }
    }
    if (!changed) cout << -1 << endl;
    else cout << best.first << " " << best.second << endl;
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
