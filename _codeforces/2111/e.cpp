/*
Problem link: https://codeforces.com/contest/2111/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

/*
op order:
c b
c a
b a

a -> c bad ignore, if you can convert back why even
b -> c good if can convert to a after, pair with c -> a
c -> a good
b -> a good
c -> b good

c -> a first
b -> c -> a second
b -> a third
c -> b -> a fourth

*/

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int b2c = 0;
    int b2a = 0;
    int c2a = 0;
    int c2b = 0;
    int b2c2a = 0;
    int c2b2a = 0;
    int c2btemp = 0;
    int b2ctemp = 0;
    for (int i = 0; i < q; i++) {
        char x, y; cin >> x >> y;
        if (x == y || x == 'a') continue;
        if (x == 'b' && y == 'c') {
            b2c++;
            b2ctemp++;
        } else if (x == 'b' && y == 'a') {
            b2a++;
            if (c2btemp > 0) {
                c2b2a++;
                c2btemp--;
            }
        } else if (x == 'c' && y == 'b') {
            c2b++;
            c2btemp++;
        } else if (x == 'c' && y == 'a') {
            c2a++;
            if (b2ctemp > 0) {
                b2c2a++;
                b2ctemp--;
            }
        }

    }
    for (char& c : s) {
        if (c == 'a') continue;
        else if (c == 'c') {
            if (c2a > 0) {
                c = 'a';
                c2a--;
            } else if (c2b2a > 0 && c2b > 0 && b2a > 0) {
                c2b--;
                b2a--;
                c2b2a--;
                c = 'a';
            } else if (c2b > 0) {
                c2b--;
                c = 'b';
            }
        } else if (c == 'b') {
            if (b2a > 0) {
                b2a--;
                c = 'a';
            } else if (b2c2a > 0 && b2c > 0 && c2a > 0) {
                b2c--;
                c2a--;
                b2c2a--;
                c = 'a';
            }
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
