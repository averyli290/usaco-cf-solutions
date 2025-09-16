/*
Problem link: https://codeforces.com/contest/2139/problem/C
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

/*
backwards, double the smaller one
*/

void solve() {
    ll k, x; cin >> k >> x;
    vi ans;
    while (x != (1LL << k)) {
        if (x < (1LL << k)) {
            ans.push_back(1);
            x <<= 1;
        } else {
            ans.push_back(2);
            x -= ((1LL << (k + 1)) - x);
        }
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
