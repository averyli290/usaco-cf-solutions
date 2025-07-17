/*
Problem link: https://codeforces.com/contest/2059/problem/C
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
can only add 1 or greater, if ever add 2, then that prefix cannot contribute
to mex because sum is too large
*/

void solve() {
    int n, t; cin >> n;
    vector<vll> a(n, vll(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> done(n, false);
    vector<int> b(n, 0);
    for(int j = n - 1; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            if (a[i][j] != 1) done[i] = true;
            if (!done[i]) b[i]++;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << done[i] << " ";
    // }
    // cout << endl;
    sort(all(b));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (ans <= b[i]) ans++;
    }
    cout << min(ans, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
