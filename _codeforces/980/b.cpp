/*
Problem link: https://codeforces.com/problemset/problem/980/B
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

/*
..........
.xxxx.....
.xx.x.....
..........


....
.x..
....
....

h = # of x's

h <= 2 * 

even always good
*/


void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        if (n % 2 == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << ".";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                if (i == n / 2) cout << "#";
                else cout << ".";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << ".";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << ".";
            }
            cout << endl;

        }
        
    }
    else if (k == 3) {
        if (n < 5) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << ".";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                if (i == n / 2 || i == n / 2 - 1 || i == n / 2 + 1) cout << "#";
                else cout << ".";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << ".";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << ".";
            }
            cout << endl;

        }
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ".";
        }
        cout << endl;
        cout << ".";
        if (k % 2 == 0) {
            for (int i = 1; i < n - 1; i++) {
                if (i <= k / 2) cout << "#";
                else cout << ".";
            }
            cout << ".";
            cout << endl;
            cout << ".";
            for (int i = 1; i < n - 1; i++) {
                if (i <= k / 2) cout << "#";
                else cout << ".";
            }
            cout << ".";
            cout << endl;
        } else {
            for (int i = 1; i < n - 1; i++) {
                if (i <= k / 2 + 1) cout << "#";
                else cout << ".";
            }
            cout << ".";
            cout << endl;
            cout << ".";
            for (int i = 1; i < n - 1; i++) {
                if (i <= k / 2 + 1 && i != k / 2) cout << "#";
                else cout << ".";
            }
            cout << ".";
            cout << endl;
        }
        for (int i = 0; i < n; i++) {
            cout << ".";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
