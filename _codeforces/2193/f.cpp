/*
Problem link: https://codeforces.com/contest/2193/problem/F
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

/*
the vet said ur fat...
https://www.youtube.com/watch?v=GzTAi3JQ3RM

dp[i][0] = finish column at x=i, end at bot
dp[i][1] = finish column at x=i, end at top
*/

void solve() {
    int n; cin >> n;
    ll ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
    map<ll, vll> mp;
    vll xvals(n), yvals(n);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        xvals[i] = x;
    }
    for(int i = 0; i < n; i++) {
        ll y; cin >> y;
        yvals[i] = y;
    }
    for(int i = 0; i < n; i++) mp[xvals[i]].push_back(yvals[i]);

    mp[ax].push_back(ay);
    mp[bx].push_back(by);
    int m = sz(mp);
    vector<vll> dp(m + 1, vll(2));
    dp[0][0] = 0ll;
    dp[0][1] = 0ll;

    auto ptr = mp.begin();
    int i = 0;
    ll prevx = ax;
    ll prevtop = ay;
    ll prevbot = ay;
    for(auto [x, v] : mp) {
        if (x == ax) continue;
        ll bot = 1e9;
        ll top = 0;
        for(ll val : v) {
            bot = min(bot, val);
            top = max(top, val);
        }

        ll diff = top - bot;
        dp[i + 1][0] = min(dp[i][0] + abs(prevbot - top) + diff, dp[i][1] + abs(prevtop - top) + diff);
        dp[i + 1][1] = min(dp[i][0] + abs(prevbot - bot) + diff, dp[i][1] + abs(prevtop - bot) + diff);
        // debug(i);
        // debug(dp[i + 1][0]);
        // debug(dp[i + 1][1]);
        i++;
        prevx = x;
        prevbot = bot;
        prevtop = top;
    }
    cout << (bx - ax) + min(dp[m - 1][0], dp[m - 1][1]) << endl;

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
