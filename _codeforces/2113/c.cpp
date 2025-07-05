/*
Problem link: https://codeforces.com/contest/2113/problem/C
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
use explosion where it kills the least amount of gold

after first explosion, every other piece of gold is obtainable by incrementally
perturbing explosion location and blowing up edges
*/

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    int tot_gold = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'g') tot_gold++;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (g[i][j] == 'g' ? 1 : 0);
        }
    }

    int destroyed = 10000000;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.') {
                int lr = max(1, i - (k - 1));
                int hr = min(n, i + (k - 1));
                int lc = max(1, j - (k - 1));
                int hc = min(m, j + (k - 1));
                // cout << lr << " " << hr << " " << lc << " " << hc << endl;
                // cout << 1 << " " << n << " " << 1 << " " << m << endl;
                destroyed = min(pref[hr][hc] - pref[lr - 1][hc] - pref[hr][lc - 1] + pref[lr - 1][lc - 1], destroyed);
            }
        }
    }
    cout << tot_gold - destroyed << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}


