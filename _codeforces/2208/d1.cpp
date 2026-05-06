/*
Problem link: https://codeforces.com/problemset/problem/2208/D1
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == '1') {
                adj[i][j] = true;
            }
        }
    }

    vector<bool> used(n, false);

    function<int()> get_sink = [&]() {
        for(int i = 0; i < n; i++) {
            if (used[i]) continue;
            int tot = 0;
            for(int j = 0; j < n; j++) {
                if (used[j]) continue;
                tot += adj[i][j];
            }
            if (tot == 1) return i;
        }
        return -1;
    };

    int left = n;
    vector<vector<bool>> ans(n, vector<bool>(n, false));
    while (left > 0) {
        int cur = get_sink();
        debug(cur);
        for(int i = 0; i < n; i++) {
            if (!used[i] and i != cur) {
                if (adj[i][cur]) {
                    ans[i][cur] = true;
                }
            }
        }
        used[cur] = true;
        left--;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (ans[i][j]) cout << i << " " << j << endl;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i != j && ans[i][j]) {
                if(!adj[i][j]) {
                    cout << "NO" << endl;
                    return;
                }
                for(int k = 0; k < n; k++) {
                    if (i != k && j != k && ans[i][k] && ans[k][j]) {
                        cout << i << " " << j << " " << k << endl;
                        cout << "NO" << endl;
                        return;
                    }
                }
            } 
        }
    }
    cout << "YES" << endl;

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
