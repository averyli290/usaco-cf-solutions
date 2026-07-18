
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
binary search for start of interval
*/

void solve() {
    int n, q; cin >> n >> q;
    ll left = 0ll;
    ll right = 0ll;
    vll starts;
    vector<vll> intervals;
    vector<pll> ranges;
    bool add = true;
    for(int i=0;i<n;i++) {
        int b, x; cin >> b >> x;
        if (b == 1) {
            right++;
            if (add) intervals.push_back(vll{});
            intervals[sz(intervals)-1].push_back(x);
            add = false;
        } else {
            ranges.push_back({left, right});
            starts.push_back(left);
            add = true;
            left = right * (x + 1);
            right = left;
        }
    }

    if (left < right) {
        ranges.push_back({left, right});
        starts.push_back(left);
    }

    for(pll r : ranges) {
        cout << r.first << " " << r.second << endl;
    }
    for(vll r : intervals) {
        debug("HERE");
        for(ll i : r) {
            cout << i << " ";
        }
        cout << endl;
    }

    for(int Q = 0; Q < q; Q++) {
        ll k; cin >> k; k--;
        ll idx = upper_bound(all(starts), k) - starts.begin() - 1ll;
        // debug(k);
        // debug(idx);
        while(k >= ranges[idx].second) {
            // debug(k);
            // debug(ranges[idx].second);
            k %= ranges[idx].second;
            idx = upper_bound(all(starts), k) - starts.begin() - 1ll;
            // ll idx = lower_bound(all(starts), k) - starts.begin();
        }
        // debug(idx);
        // debug(k - ranges[idx].first);
        cout << intervals[idx][k - ranges[idx].first] << " ";
    }
    cout << endl;
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
