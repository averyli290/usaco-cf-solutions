/*
Problem link: https://codeforces.com/contest/2065/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;


void solve() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << 1 << endl;
            return;
        }
    }
    cout << s.length() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
