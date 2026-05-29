/*
Problem link: https://codeforces.com/contest/1986/problem/B
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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int minval = 0;
            bool rep = true;
            if (i > 0) minval = max(minval, a[i - 1][j]);
            if (j > 0) minval = max(minval, a[i][j - 1]);
            if (i < n - 1) minval = max(minval, a[i + 1][j]);
            if (j < m - 1) minval = max(minval, a[i][j + 1]);
            if (i > 0 && a[i][j] <= a[i - 1][j]) rep = false;
            if (j > 0 && a[i][j] <= a[i][j - 1]) rep = false;
            if (i < n - 1 && a[i][j] <= a[i + 1][j]) rep = false;
            if (j < m - 1 && a[i][j] <= a[i][j + 1]) rep = false;
            if (rep) a[i][j] = minval;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
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
