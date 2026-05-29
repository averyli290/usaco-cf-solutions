/*
Problem link:
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
if all numbers are equal, done
must make the greatest number not single
if the greatest number is odd and not everything same, add one and divide by 2

for even, check if can just increase all odd numbers if lo = hi - 1
edge case for when hi = 2, check if can divide by 2 to get 1

*/

void solve() {
    int n; cin >> n;
    vi a(n);
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    sort(all(a));

    int lo = a[0];
    int hi = a[n - 1];

    int ans = 0;
    while (lo < hi) {
        int cur = pq.top();
        if (cur % 2 == 0) {
            if (lo == hi - 1) {
                // debug(lo);
                // debug(hi);
                int ans1 = 0;
                int ans2 = 0;
                while (!pq.empty()) {
                    int temp = pq.top();
                    if (temp == lo) ans1++;
                    else ans2++;
                    pq.pop();
                }
                if (hi == 2) {
                    cout << ans + min(ans1, ans2) << endl;
                } else {
                    cout << ans + ans1 << endl;
                }
                return;
            }
            cur /= 2;
            ans++;
        } else {
            cur++;
            cur /= 2;
            ans += 2;
        }
        pq.pop();
        lo = min(cur, lo);
        pq.push(cur);
        hi = pq.top();
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
