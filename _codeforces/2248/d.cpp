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
greedy assign
*/

void solve() {
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;
    /*
    x: st
    0: 00
    1: 01
    2: 10
    3: 11
    */
    vector<vi> pref(n + 1, vi(4, 0));
    for(int i = 0; i < n; i++) {
        int x = s[i] - '0';
        int y = t[i] - '0';
        int xx = x * 2 + y;
        pref[i + 1] = pref[i];
        pref[i + 1][xx]++;
    }
    while(q--) {
        int l, r; cin >> l >> r;
        array<int, 4> arr = {0,0,0,0};
        for(int i = 0; i < 4; i++) {
            arr[i] = pref[r][i] - pref[l - 1][i];
        }
        int diff = abs(arr[1] - arr[2]);
        if (arr[0] + arr[3] >= diff) cout << "YES" << endl;
        else cout << "NO" << endl;
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