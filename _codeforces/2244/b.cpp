/*
Problem link: https://codeforces.com/contest/2244/problem/B
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
https://www.youtube.com/watch?v=9qN9EF-6IcI
*/

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        if (a[i] < i + 1) {
            cout << "NO" << endl;
            return;
        }
        a[i + 1] += a[i] - (i + 1);
        a[i] = i + 1;
    }
    if (n > 1 && a[n - 1] <= a[n - 2]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
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
