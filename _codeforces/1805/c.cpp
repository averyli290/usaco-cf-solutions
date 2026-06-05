/*
Problem link: https://codeforces.com/contest/1805/problem/C
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
=ax^2+(b-k)x+c

search for k s.t.
(b-k)^2-4ac < 0
=b^2-2bk+k^2-4ac

b^2-2bk+k^2-4ac < 0
-2bk+k^2<4ac-b^2
k(k-2b) < 4ac-b^2

minimize k^2 - 2bk
root at k=2b, k = 0

2k-2b
minimum at k=b
*/

void solve() {
    int n, m; cin >> n >> m;
    vll k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }
    sort(all(k));
    for(int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        auto ptr1 = lower_bound(all(k), b);
        auto ptr2 = upper_bound(all(k), b);
        bool done = false;
        if (ptr1 != k.end()) {
            ll v = *ptr1;
            if (v*(v-2*b)<4*a*c-b*b) {
                cout << "YES" << endl;
                cout << v << endl;
                done = true;
            }
        }
        if (!done && ptr2 != k.begin()) {
            ptr2--;
            ll v = *ptr2;
            if (v*(v-2*b)<4*a*c-b*b) {
                cout << "YES" << endl;
                cout << v << endl;
                done = true;
            }
        }
        if (!done) {
            cout << "NO" << endl;
        }
    }
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
