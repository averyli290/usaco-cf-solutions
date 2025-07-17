/*
Problem link: https://codeforces.com/contest/1856/problem/B
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
    ll n; cin >> n;
    map<ll, ll> m;
    ll sum = 0;
    for(int i=0;i<n;i++) {
        ll x; cin >> x;
        m[x]++;
        sum += x;
    }
    if (n == 1) {
        cout << "NO" << endl;
        return;
    }
    //cout << "sum: " << sum <<endl;
    if (2 * m[1] + (n - (m[1]) - 1) >= sum) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
