/*
Problem link: https://codeforces.com/contest/2128/problem/C
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
    int n; cin >> n;
    int curmin;
    cin >> curmin;
    bool good = true;
    for (int i=1;i<n;i++) {
        int x; cin >> x;
        if (x - curmin >= curmin) {
            good = false;
        }
        curmin = min(curmin, x);
    }
    cout << (good ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
