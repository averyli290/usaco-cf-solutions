/*
Problem link: https://atcoder.jp/contests/abc461/tasks/abc461_d
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


void solve() {
    int H, W, K; cin >> H >> W >> K;
    vector<vi> a(H, vi(W, 0));
    for(int i=0;i<H;i++) {
        string s; cin >> s;
        for(int j=0;j<W;j++) a[i][j] = s[j] - '0';
    }
    vector<vi> pref(H+1, vi(W+1,0));
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i - 1][j - 1];
            // cout << pref[i][j] << " ";
        }
        // cout << endl;
    }
    ll ans = 0ll;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            for(int x = i; x <= H; x++) {
                for(int y = j; y <= W; y++) {
                    if (pref[x][y] - pref[i-1][y] - pref[x][j - 1] + pref[i - 1][j - 1] == K) {
                        ans++;
                        // cout << i << " " << j << " " << x << " " << y << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
