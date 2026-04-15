/*
Problem link: https://codeforces.com/contest/2191/problems/B
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*

0 1 1 0
0 0 1 1
1 2
1 0
2 0

0 0 2
1 1

*/

void solve() {
    int n; cin >> n;
    int nz = 0;
    int no = 0;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) nz++;
        else if (a[i] == 1) no++;
    }
    if (nz == 0) {
        cout << "NO" << endl;
    } else if (nz == 1) {
        cout << "YES" << endl;
    } else {
        if (no > 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
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
