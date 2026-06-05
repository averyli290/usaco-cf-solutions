/*
Problem link: https://codeforces.com/contest/1011/problem/D
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

int query(int x) {
    cout << x << endl; cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int m, n; cin >> m >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        int res = query(1);
        if (res == 0) return;
        a[i] = res * -1;
    }

    int lo = 1;
    int hi = m + 1;
    int ct = 0;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        int res = query(mid);
        res *= a[ct % n];
        if (res == 0) return;
        if (res < 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        ct++;
    }
    cout << lo << endl; cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
