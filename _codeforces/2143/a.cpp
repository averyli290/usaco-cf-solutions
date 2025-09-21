/*
Problem link: https://codeforces.com/contest/2143/problem/A
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
*/

void solve() {
    int n; cin >> n;
    vi a(n, 0);
    int l, r;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        if (x == n) {
            l = i;
            r = i;
        }
    }
    for(int i = n - 1; i > 0; i--) {
        if (a[max(0, l - 1)] == i) {
            l--;
        } else if (a[min(n - 1, r + 1)] == i) {
            r++;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
