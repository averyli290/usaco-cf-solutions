/*
Problem link: https://codeforces.com/contest/2111/problem/D
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
    vector<pii> a(m);
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        a[i] = pii({x / 100, x});
    }
    sort(all(a));

    for(int i = 0; i < n; i++) {
        for(int p = 0; p < 6; p++) {
            if ((p + i) % 2 == 0) {
                cout << a[i / 2].second << " ";
            } else {
                cout << a[m - i / 2 - 1].second << " ";
            }
        }
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
