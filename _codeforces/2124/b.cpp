/*
Problem link: https://codeforces.com/contest/2124/problem/B
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
    vi a(n);
    for(int i =0;i <n;i++) {
        cin >> a[i];
    }
    if (a[0] == 0) {
        cout << 0 << endl;
        return;
    }
    cout << min(a[0] * 2, a[0] + a[1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
