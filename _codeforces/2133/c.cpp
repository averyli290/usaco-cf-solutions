/*
Problem link: https://codeforces.com/contest/2133/problem/C
*/

/*
find starting point
iterate through rest, get the ones with exactly one less each time
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
    vector<vi> b(n + 1, vi{});
    string s = "";
    for(int i = 1; i <= n; i++) s += " " + to_string(i);
    for(int i = 1; i <= n; i++) {
        int x;
        cout << "? " << i << " " << n << s << endl;
        cout.flush();
        cin >> x;
        b[x].push_back(i);
    }
    string ans = "";
    int len, prev;
    for(int i = n; i >= 1; i--) {
        if (sz(b[i]) > 0) {
            len = i;
            prev = b[i][0];
            ans += " " + to_string(prev);
            break;
        }
    }
    for(int i = len - 1; i >= 1; i--) {
        for (int j = 0; j < sz(b[i]); j++) {
            int x;
            cout << "? " << prev << " 2 " << prev << " " << b[i][j] << endl;
            cout.flush();
            cin >> x;
            if (x == 2) {
                ans += " " + to_string(b[i][j]);
                prev = b[i][j];
                break;
            }
        }
    }
    cout << "! " << len << ans << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}