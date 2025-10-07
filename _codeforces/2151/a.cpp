/*
Problem link:
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
    vi a(m);
    int x = 0;
    int temp = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        if (i > 0 && a[i] == 1) {
            temp += 1;
        }
        x = max(x, a[i]);
    }
    if (temp == 0) {
        cout << n - x + 1 << endl;
    } else if (temp >= 1) {
        cout << 1 << endl;
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
