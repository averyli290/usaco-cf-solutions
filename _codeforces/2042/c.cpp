/*
Problem link: https://codeforces.com/contest/2042/problem/C
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
    int n, k; cin >> n >> k;
    vi a(n);
    string s; cin >> s;
    for(int i = 0; i < n; i++) a[i] = s[i] - '0';
    int right = n - 1;
    while (right >= 0 && a[right] == 1) right--;
    vi b;
    int prev = 0;
    int ctr = 0;
    for(int i = 0; i <= right; i++) {
        if (a[i] == 1 && prev == 0) {
            if (ctr != 0) b.push_back(ctr);
            ctr = 0;
        }
        prev = a[i];
        if (a[i] == 0) ctr--;
        else ctr++;
        //cout << i << ": " << ctr << endl;
    }
    if (ctr != 0) b.push_back(ctr);
    // save last for later ?
    if (n - 1 - right > 0) b.push_back(n - 1 - right);
    for(int v : b) cout << v << " ";
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
