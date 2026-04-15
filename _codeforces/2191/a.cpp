/*
Problem link: https://codeforces.com/contest/2191/problems/A
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
    vector<pii> a(n);
    vi c(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
        c[i] = i % 2;
    }
    sort(all(a));
    for(int i = 0; i < n - 1; i++) {
        if (c[a[i].second] == c[a[i + 1].second]) {
            cout << "NO" << endl;
            return;
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
