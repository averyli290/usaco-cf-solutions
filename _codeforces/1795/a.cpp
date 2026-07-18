/*
Problem link: https://codeforces.com/problemset/problem/1795/A
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
    int a, b; cin >> a >> b;
    string c, d; cin >> c >> d;
    int b1 = 0;
    int b2 = 0;
    for(int i = 1; i < a; i++) if (c[i] == c[i - 1]) b1++;
    for(int i = 1; i < b; i++) if (d[i] == d[i - 1]) b2++;
    if (b1 + b2 > 1) {
        cout << "NO" << endl;
        return;
    }
    if (b1 + b2 == 0) {
        cout << "YES" << endl;
        return;
    }
    if (c[a - 1] != d[b - 1]) cout << "YES" << endl;
    else cout << "NO" << endl;
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
