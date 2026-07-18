/*
Problem link: https://codeforces.com/contest/2158/problem/D
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

1010101
0101010

1010101
0100101
0101011


1010101
0000000

make all 0 by finding group of 2


0101010
0111111
0100000
0101111
0101000
0101010??

0000000

*/

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    char chud = '0';
    int ans = 0;
    vector<pii> ops;
    for(int i = 0; i < n; i++) {
        if (s[i] != chud) {
            ops.push_back(1, i + 1);
            chud = chud == '0' ? '1' : '0';
            ans++;
        }
    }
    for(int i = 0; i < n; i++) {
        if (t[i] != chud) {
            ops.push_back(i + 1, n);
            chud = chud == '0' ? '1' : '0';
            ans++;
        }
    }
    cout << ans << endl;
    for(auto [l, r] : ops) {
        cout << l << " " << r << endl;
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
