/*
Problem link: https://codeforces.com/contest/2110/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

/*
bin search for answer
*/

vector<vector<pll>> p;
vector<vector<pll>> pb;
vll b;
int n;

bool ok(ll cap) {
    vector<ll> dp(n, -1);
    dp[0] = min(b[0], cap);
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) continue;
        for (auto [w, x] : p[i]) {
            if (w <= cap && dp[i] >= w) {
                dp[x] = min(cap, max(dp[i], w) + b[x]);
            }
        }
    }
    return dp[n - 1] > -1;
}

void solve() {
    int m; cin >> n >> m;
    b.assign(n, 0);
    p.assign(n, vector<pll>{});
    pb.assign(n, vector<pll>{});
    ll low = 0; ll high = 0;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) {
        ll s, t, w; cin >> s >> t >> w;
        s--; t--;
        p[s].push_back({w, t});
        pb[t].push_back({w, s});
        high += w;
    }
    ll ans = -1;
    while (high - low > 1) {
        ll mid = (high + low) / 2;
        //cout << low << " " << mid << " " << high << endl;
        if (ok(mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
