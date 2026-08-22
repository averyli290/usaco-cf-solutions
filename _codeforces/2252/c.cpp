/*
Problem link: https://codeforces.com/contest/2252/problem/C
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
https://www.youtube.com/watch?v=zWoSvb1_vXQ
*/

void solve() {
    int n, m; cin >> n >> m;
    vector<vll> a(n, vll(m, 0ll));
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    function<bool(int)> check = [&] (int mid) {
        multiset<ll> vs(all(v));
        priority_queue<ll> pq;
        ll cursum = 0ll;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                pq.push(-a[i][j]);
                cursum += a[i][j];
                if (sz(pq) > mid) {
                    cursum += pq.top();
                    pq.pop();
                }
                if (cursum >= *vs.begin()) {
                    return true;
                }
            }
            vs.erase(vs.lower_bound(v[i]));
        }
        return false;
    };

    int lo = 1;
    int hi = m;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << hi << endl;
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
