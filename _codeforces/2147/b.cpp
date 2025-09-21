/*
Problem link: https://codeforces.com/contest/2147/problem/B
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

1, 2, 3, 4

1 1
1 2 1 2
3 1 2 3 2 1
4 3 1 2 4 2 1 3
5 4 3 1 2 5 4 2 1 3 -> 5 4 3 1 2 5 3 1 4 2
5 1 3 4 2 5 2 4 3 1

6 5 4 3 2 1 6 1 2 3 4 5

*/

void solve() {
    int n; cin >> n;
    vi a(n * 2);
    int ct = n;
    for(int i = 0; i < n; i++) {
        a[i] = ct;
        ct--;
    }
    ct++;
    a[n] = n;
    for(int i = n + 1; i < 2 * n; i++) {
        a[i] = ct;
        ct++;
    }
    for(int v : a) {
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
