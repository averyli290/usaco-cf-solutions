/*
Problem link: https://codeforces.com/contest/2130/problem/C
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


struct piii {
    int a;
    int b;
    int c;
};

bool cmp(const piii &x, const piii &y) {
    if (x.a != y.a) return x.a < y.a;
    if (x.b != y.b) return x.b < y.b;
    return x.c < y.c;
}

void solve() {
    int n; cin >> n;
    vector<piii> v(n);
    for(int i = 0;i<n;i++) {
        int x, y; cin >> x >> y;
        v[i] = piii{x, y, i};
    }
    sort(all(v), cmp);
    int m = 0;
    vi ans;
    for(int i = 0; i < n; i++) {
        int a = v[i].a;
        int b = v[i].b;
        if (b > m) {
            ans.push_back(v[i].c);
        }
        m = max(b, m);
    }
    cout << sz(ans) << endl;
    sort(all(ans));
    for(int v : ans) {
        cout << v + 1 << " ";
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