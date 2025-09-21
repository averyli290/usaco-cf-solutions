/*
Problem link: https://codeforces.com/contest/2146/problem/C
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
1: everythign to left must be less, everythign to right must be greater, value is equal to index
0: something to left must be greater, value is not equal to index
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi ans(n, 0);
    vi not_used;
    //int not_used = 0;
    for(int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            if (sz(not_used) == 1) {
                cout << "NO" << endl;
                return;
            } else {
                for(int j = 0; j < sz(not_used); j++) {
                    ans[not_used[j] - 1] = not_used[(j + 1) % sz(not_used)];
                }
                ans[i - 1] = i;
            }
            not_used.clear();
        } else {
            not_used.push_back(i);
        }
    }
    for(int j = 0; j < sz(not_used); j++) {
        ans[not_used[j] - 1] = not_used[(j + 1) % sz(not_used)];
    }

    for(int i = 0; i < n; i++) {
        if (s[i] == '0' && ans[i] == i + 1) { // verify value is not equal to index
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(int v : ans) {
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
