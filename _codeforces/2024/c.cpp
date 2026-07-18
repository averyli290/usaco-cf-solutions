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



void solve() {
    int n;cin >> n;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = array<int, 3>{x + y, x, y};
    }
    sort(all(a));
    for(auto [t, x, y] : a) {
        cout << x << " " << y << " ";
    }
    cout << endl;
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
