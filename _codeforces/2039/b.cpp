/*
Problem link: https://codeforces.com/contest/2039/problem/B
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
    string s; cin >> s;
    if (sz(s) == 1) {
        cout << -1 << endl;
        return;
    }
    int n = sz(s);
    for(int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << s[i] << s[i] << endl;
            return;
        }
    }
    for(int i = 0; i < n - 2; i++) {
        if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
            cout << s.substr(i, 3) << endl;
            return;
        }
    }
    cout << -1 << endl;
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
