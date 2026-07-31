/*
Problem link: https://codeforces.com/contest/2193/problem/A
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
the vet said ur fat...
https://www.youtube.com/watch?v=GzTAi3JQ3RM
*/

void solve() {
    ll n, s, x; cin >> n >> s >> x;
    ll z = 0ll;
    for(int i = 0 ; i < n; i++) {
        ll y; cin >> y;
        z += y;
    }
    if (z <= s && (s - z) % x == 0) cout << "YES" << endl;
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
