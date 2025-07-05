/*
Problem link: https://codeforces.com/contest/2113/problem/B
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
5 5 2 2
-1 -1 4 -1

. . . . .
. . . . .
. . . . .
. . . . .
x . . x x
. . . x x
*/

void solve() {
    int w, h, a, b; cin >> w >> h >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    if(x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (x1 + a > x2) {
        if ((y1 - y2) % b == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if(y1 > y2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (y1 + b > y2) {
        if ((x1 - x2) % a == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }

    if ((y1 - y2) % b == 0 || (x1 - x2) % a == 0) cout << "YES" << endl;
    else cout << "NO" <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
