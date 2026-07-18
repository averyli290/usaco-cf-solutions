/*
Problem link: https://codeforces.com/contest/2037/problem/E
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
*/

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}


void solve() {
    int n; cin >> n;
    vi ans(n);
    int prev = query(1, n);
    if (prev == 0) {
        cout << "! IMPOSSIBLE" << endl; cout.flush();
        return;
    }
    for(int i = n - 1; i >= 2; i--) {
        int cur = query(1, i);
        if (cur < prev) ans[i] = 1;
        else ans[i] = 0;
        prev = cur;
    }
    if (prev > 0) ans[0] = 0;
    else ans[0] = 1;
    cout << "! ";
    for(int i : ans) cout << i;
    cout << endl; cout.flush();
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
