/*
Problem link: https://codeforces.com/contest/2241/problem/C
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

// cf why did u go down at the start of my virtual :(

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ct = 0;
    for(int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) ct++;
    }
    if (ct == 0) {
        cout << 1 << endl;
    } else if (ct == 1) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
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