/*
Problem link: https://codeforces.com/contest/2024/problem/D
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
    int n; cin >> n;
    vll a(n), pref(n + 1, 0ll);
    vi b(n);
    vector<vector<pll>> adj(n, vector<pll>{});
    for(int i = 0;i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    for(int i = 0;i < n; i++) {
        cin >> b[i];
        if (i >= 1) adj[i].push_back({i - 1, 0ll});
        if (b[i] > i) {
            adj[i].push_back({b[i] - 1, a[i]});
        }
    }
 
    vll dist(n, LLONG_MAX);
    priority_queue<pll> pq;     // ermm remember this is a max heap dude
    pq.push({0,0});
    dist[0] = 0ll;
    ll ans = 0ll;
 
    while(!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        d = -d;
        ans = max(ans, pref[cur + 1] - dist[cur]);
        for(auto [neig, w] : adj[cur]) {
            if (dist[cur] + w < dist[neig]) {
                dist[neig] = dist[cur] + w;
                pq.push({-(dist[cur] + w), neig});
            }
        }
    }
 
    for(int i = 0; i < n; i++) {
        ans = max(ans, pref[i + 1] - dist[i]);
    }
 
    cout << ans << endl;
 
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