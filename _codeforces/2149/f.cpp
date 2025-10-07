/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

/*
takes 2 turns to move 1 step
2 1

1 + 2 + 1: 3 / 2
3 turns to move 2 steps

1 + 2 + 3 + 1: 6 / 3
4 turns to move 3 steps

1 + 2 + 3 + 4 + 1: 10 / 4
*/


int check(int h, int d, int s) {
    // taking s consecutive steps
    int expend = s * (s + 1) / 2;
    debug(expend);
    if (expend == 1) {
        return 2 * d - 1;
    }
    int tot = 0;
    if (expend >= h) {
        tot += expend - h + 1;
    }

    debug(h);
    int ct = (h - 1) / (expend - 1);
    tot += (s + 1) * ct;
    int rem = d % s;
    tot += rem;
    debug(ct);
    debug(tot);
    debug(rem);
    return tot;
}

void solve() {
    int h, d; cin >> h >> d;
    int ans = INT_MAX;
    int low = 0;
    int high = d + 1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        cout << low << " " << mid << " " << high << endl;
        int val = check(h,d,mid);
        if (val > -1) {
            ans = min(ans, val);
            low = mid;
        } else {
            high = mid;
        }
        debug(ans);
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