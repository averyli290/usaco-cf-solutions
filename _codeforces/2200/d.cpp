/*
Problem link: https://codeforces.com/contest/2205/problem/D
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
    int n, x, y; cin >> n >> x >> y;
    vi a(n);
    vi b, c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minb = n + 1;
    int minbidx = n + 1;
    int ctr = 0;
    for(int i = x; i < y; i++) {
        b.push_back(a[i]);
        if (a[i] < minb) {
            minb = a[i];
            minbidx = ctr;
        }
        ctr++;
    }
    for(int i = 0; i < n; i++) {
        if (i < x || i >= y) {
            c.push_back(a[i]);
        }
    }
    ctr = 0;
    while(ctr < sz(c) && c[ctr] < b[0]) {
        cout << c[ctr] << " ";
        ctr++;
    }
    int ctr2 = 0;
    for(int i = x; i < y; i++) {
        cout << b[(minbidx + ctr2) % (y - x)] << " ";
        ctr2++;
    }
    while(ctr < sz(c)) {
        cout << c[ctr] << " ";
        ctr++;
    }
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
