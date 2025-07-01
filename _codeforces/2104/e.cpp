/*
Problem link: https://codeforces.com/contest/2104/problem/E
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
match string up greedily to as far as possible

at each index, for a given character c, store the next index which it appears.
want to add the character with the largest next index, it gets furthest down the string
in matching.

all queries which math up to a position p in the string have to have the same answer
dp[i] = # of characters to add given that remaining string possible to match starts at index i
dp[n] = 0
dp[i] = get character which starts the furthest down the line,
        1 + dp[index of that character] (have to add 1 for including that character)
*/


void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int q; cin >> q;

    vi dp(n + 1, 0);    // dp[i] stores ans given string remaining starts at index i
    vector<vi> a(n + 2, vi(k, n));  // a[i][j] = index which char j next appears at index i or later
    for (int i = n - 1; i >= 0; i--) {
        a[i] = a[i + 1];
        dp[i] = 1 + dp[*max_element(all(a[i]))];  // insert element which gets us further down string
        a[i][s[i] - 'a'] = i;
    }

    while (q--) {
        string x;
        cin >> x;
        int p = -1;
        for (int i = 0; i < sz(x); i++) {
            p = a[p + 1][x[i] - 'a'];
        }
        //cout << i << endl;
        cout << dp[p] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
