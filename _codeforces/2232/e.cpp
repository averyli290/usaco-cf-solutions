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
    int n, k; cin >> n >> s;
    for(int i = 0; i < s; i++) {
        int x, l, r; cin >> x >> l >> r;
        string st; cin >> st;
        for(int j = 0; j < x / 2; j++) {
            if (st[j] == 'R') r++;
            else l++;
        }
        int idx = r;
    }
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
