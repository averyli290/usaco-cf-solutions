/*
Problem link: https://codeforces.com/contest/2128/problem/B
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int r = n - 1;
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // min
            if (a[l] < a[r]) {
                cout << "L"; l++;
            } else {
                cout << "R"; --r;
            }
        } else {
            // max
            if (a[l] > a[r]) {
                cout << "L"; l++;
            } else {
                cout << "R"; --r;
            }
        }
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
