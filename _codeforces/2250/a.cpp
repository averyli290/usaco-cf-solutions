/*
Problem link: https://codeforces.com/contest/2250/problem/A
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

alalalaaaalalalalalllalala
*/


void solve() {
    int n; cin >> n;
    vll a(n + 2);
    vll b(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i - 1] = a[i] + 1;
    }
    b.push_back(0);
    sort(all(b));
    for(ll k : b) {
        vll c(n + 2, 0ll);
        bool good = true;
        for(int i = 1; i <= n; i++) {
            if (a[i] < k) c[i - 1] = a[i];
            else if (a[i] > k) c[i + 1] = a[i];
            else good = false;
        }
        int ct = 0;
        for(int i = 1; i <= n; i++) if (c[i] > 0ll) ct++;
        if (ct == n && good) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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
