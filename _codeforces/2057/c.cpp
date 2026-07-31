/*
Problem link: https://codeforces.com/contest/2057/problem/C
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
    ll l, r; cin >> l >> r;
    int bo = 63 - __builtin_clzll(r);

    ll a = 0ll;
    ll b = 0ll;
    ll c = 0ll;
    for(int i = bo; i >= 0; i--) {
        if(((l >> i) & 1) != ((r >> i) & 1)) {
            a += 1 << i;
            // set all the lower bits to differ, we can set b=c for now and that maximizes xor bc count is 2 for each bit
            for(int j = i - 1; j >= 0; j--) {
                b += 1 << j;
            }
            // make sure not identical now and within bounds
            c = b - 1;
            while (a == c || b == c || c < l) c++;
            cout << a << " " << b << " " << c << endl;
            return;
        }
        // if forced to match, match
        if ((l >> i) & 1) {
            a += 1 << i;
            b += 1 << i;
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
