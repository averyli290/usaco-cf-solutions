/*
Problem link: https://codeforces.com/contest/2106/problem/F
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
pretend there is wall of 1's before and after
every time there is 1, closes off top and merges bottom with next top + 1 (for flipping 1 to 0)
ans.append(top + curbot)
prevbot = curbot + 1
reset top = 0

1111

0111
1011
1101
1110

10

00
11

*/


void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    ll bot = 0;
    ll prevbot = 0;
    ll top = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '0') {
            top += i;
            bot += n - i - 1;
        } else {
            ans = max(ans, top + prevbot);
            prevbot = bot + 1;
            bot = 0;
            top = 0;
        }
        //cout << top << " " << bot << endl;
    }
    cout << max(ans, top + prevbot) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
