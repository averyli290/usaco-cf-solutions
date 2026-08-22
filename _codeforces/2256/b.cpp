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
    int n; cin >> n;
    string s; cin >> s;
    bool b = true;
    for(int i = 0; i < n; i++) {
        if (s[i] != '?') b = false;
    }
    if (b) {
        cout << 4 << endl;
        return;
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
