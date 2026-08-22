/*
Problem link: https://codeforces.com/contest/2256/problem/A
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

const ll M = 998244353;

/*
1??1

1?0???????

1?????
110011
100110

0011
1100
0110
1001

10011110101011
01011101010111
0010001
1111111
*/

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi s2(2*n, -1);
    for(int i = 0; i < 2*n; i++) {
        // debug(i);
        // debug(s[i]);
        if (s[i] == '1' && s[(i + 1) % (2 * n)] == '0') {
            s2[i] = 0;
            s2[(i + 1) % (2 * n)] = 1;
        } else {
            // cout << "here" << endl;
            if (s2[i] == -1) s2[i] = s[i] - '0';
        }
        // debug(s2[i]);
    }
    // debug(s2[2]);
    int a = 0;
    int b = 0;
    for(int i = 0; i < 2*n; i++) {
        if (i % 2 == 1) a += s2[i];
        else b += s2[i];
    }
    cout << a << " " << b << endl;
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
