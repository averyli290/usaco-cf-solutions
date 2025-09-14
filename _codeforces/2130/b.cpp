/*
Problem link: https://codeforces.com/contest/2130/problem/B
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
    int n, goal; cin >> n >> goal;
    vi a(n);
    vi b(3, 0);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        b[a[i]]++;
    }
    if (s > goal) {
        for(int v : a) {
            cout << v << " ";
        }
        cout << endl;
        return;
    }
    if (goal - s == 1) {
    for(int i = 0; i < b[0]; i++) {
        cout << "0 ";
    }
    for(int i = 0; i < b[2]; i++) {
        cout << "2 ";
    }
    for(int i = 0; i < b[1]; i++) {
        cout << "1 ";
    }
    cout << endl;

    return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}