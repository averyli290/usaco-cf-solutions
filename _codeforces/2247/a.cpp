/*
Problem link: https://codeforces.com/contest/2247/problem/A
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
    int s = 0;
    vi a(n);
    bool can = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        if (i > 0 && a[i] == a[i - 1]) can = true;
    }
    if (s == 0 || (s % 4 == 0 && can)) cout << "YES" << endl;
    else cout << "NO" << endl;
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
