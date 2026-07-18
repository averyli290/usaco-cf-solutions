/*
Problem link: https://codeforces.com/contest/2205/problem/A
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
    vi p(n);
    int hi;
    for(int i = 0; i< n; i++) {
        cin >> p[i];
        if (p[i] == n) hi = i;
    }
    swap(p[0], p[hi]);
    for(int bahls : p) cout << bahls << " ";
    cout << endl;
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
