/*
Problem link: https://codeforces.com/contest/2182/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;
const long long MOD = 998244353;

/*
can always not use box if needed


binary search for ans
greedy check
out of possible boxes which can be assigned to people, assign based on lowest required cost first and highest potential cost

use a pq based on difference between potential cost and required cost
we are guaranteed to be able to match every required cost, so we can front those as needed,
only care about increase when cant cover using beauty criteria

*/

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vi a(m);
    vi x(n), y(n), z(n);
    vector<pii> p(n);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
        p[i] = {x[i], z[i] - y[i]};
        k -= y[i];
    }

    sort(all(p));

    int lo = 0;
    int hi = n;
    int ans = 0;
    while(lo < hi) {
        int mid = (hi + lo + 1) / 2;
        bool good = false;

        int ct = 0;
        int coins = k;
        priority_queue<pii> pq; // cost, index
        vector<bool> covered(n, false);
        int i = 0;
        for(int j = 0; j < m; j++) {
            while (i < n && p[i].first <= a[j]) {
                pq.push({p[i].second, i});
                i++;
            }
            while (!pq.empty()) {
                auto [diff, idx] = pq.top();
                pq.pop();
                // int cost = y[idx];
                // coins -= cost;
                // if (coins < 0) break;
                ct++;
                covered[idx] = true;
            }
        }

        // assign rem
        vi rem;
        for(int i = 0; i < n; i++) if (!covered[i]) rem.push_back(z[i] - y[i]);
        sort(all(rem));
        for(int i = 0; i < sz(rem); i++) {
            if (coins - rem[i] < 0) break;
            coins -= rem[i];
            ct++;
        }

        good = (ct >= mid);


        if(good) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid - 1;
        }
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
