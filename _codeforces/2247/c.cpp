/*
Problem link: https://codeforces.com/contest/2247/problem/C
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
https://www.youtube.com/watch?v=9qN9EF-6IcI
*/

void solve() {
    int n; cin >> n;
    vi a(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int tot = 0;
    bool x = false;
    int o = 0;
    int z = 0;
    int t = 0;
    int ct = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            x = true;
            if (a[i] == 1) ct++;
        }
        if (a[i] == 1) o++;
        if (b[i] == 0) z++;
    }
    if (!x) {
        cout << 0 << endl;
        return;
    }
    if (o == 0 || z == 0) {
        cout << -1 << endl;
        return;
    }
    if (ct % 2 == 1) cout << 1 << endl;
    else cout << 2 << endl;
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