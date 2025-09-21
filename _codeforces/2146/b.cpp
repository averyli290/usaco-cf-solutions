/*
Problem link: https://codeforces.com/contest/2146/problem/B
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
occur only once -> only one combo
*/

void solve() {
    int n, m; cin >> n >> m;

    vi occ(m, 0);
    vector<vi> g(n);
    for(int i = 0; i < n; i++) {
        int l; cin >> l;
        vi temp(l);
        for(int j = 0; j < l; j++) {
            int a; cin >> a; a--;
            occ[a]++;
            temp[j] = a;
        }
        g[i] = temp;
    }

    for(int i = 0; i < m; i++) {
        if (occ[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    
    int ans = 1;
    for(int i = 0; i < n; i++) {
        bool good = true;
        for(int& v : g[i]) {
            // cout << v << " " << occ[v] << endl;
            occ[v]--;
            if (occ[v] == 0) {
                good = false;
            }
        }
        if (good) {
            //cout << i << endl;
            ans++;
            if (ans >= 3) {
                cout << "YES" << endl;
                return;
            }
        }
        for(int& v : g[i]) occ[v]++;
    }
    cout << "NO" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
