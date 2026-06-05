/*
Problem link: https://codeforces.com/contest/1805/problem/B
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
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << s << endl;
        return;
    }
    char v = s[0];
    int idx = 0;
    for(int i = 1; i < n; i++)  {
        if (v - s[i] >= 0) {
            v = s[i];
            idx = i;
        }
    }
    // debug(idx);
    string res = "";
    res += s[idx];
    for(int i = 0; i < n; i++) {
        if (i != idx) res += s[i];
    }
    cout << res << endl;
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
