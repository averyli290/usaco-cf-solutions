/*
Problem link: https://codeforces.com/contest/2130/problem/E1
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
(()

0 => ((, )), )(
1 => ()

for string ab, test (((abb

((( )) ) => )) 3
((( (( ( => (( 0
((( )( ( => )( 1
((( () ) => () 2

((())) => )) 3
(((((( => (( 0
((()(( => )( 1
(((()) => () 2

find a (), build off that, can binary search for it

if left > 0, go left
if right > 0, go right
if left == 0 and right == 0, must cross in between

search for ( first

*/

int search(int n, int left, int right) {
    int l = left;
    int r = right;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? " << m << " ";
        for(int i = 1; i <= m; i++) {
            cout << i << " ";
        }
        cout << "\n";
        cout.flush();
        int res; cin >> res;
        if (res == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    int n; cin >> n;
    string forward = to_string(search(n, 0, n + 1));
    string temp = forward + " " + forward + " " + forward;

    string ans = "";
    for(int i = 1; i < n ; i += 2) {
        cout << "? " << 6 << " " << temp << " " << i << " " << i+1 << " " << i+1 << "\n";
        cout.flush();
        int x; cin >> x;
        if (x == 3) {
            ans += "))";
        } else if (x == 0) {
            ans += "((";
        } else if (x == 1) {
            ans += ")(";
        } else {
            ans += "()";
        }
    }
    if (n % 2 == 1) {
        cout << "? " << 2 << " " << forward << " " << n << "\n";
        cout.flush();
        int x; cin >> x;
        if (x == 1) {
            ans += ")";
        } else {
            ans += "(";
        }
    }
    cout << "! " << ans << "\n";
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
