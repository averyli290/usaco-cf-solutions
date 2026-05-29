/*
Problem link: https://codeforces.com/contest/2145/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
placing an inversion at (left, right) adds left * (n - right + 1) subsegments

how may subsegments do NOT have an inversion
there are n(n-1)/2 subsegments which do not have an inversion
(s_i * (s_i - 1)) / 2 for s_i >= 2 where s_i is the size of an increasing subsegment
brute force these, create increasing subsegments which count non-inversions
which are in turn always larger than later subsegments (which will add inversions)

*/


void solve() {
    int n, k; cin >> n >> k;
    int left = 1;
    int right = n;
    k = (n * (n - 1)) / 2 - k;
    // debug(k);

    bool done = false;
    vi ans(n);
    function <void(vi, int, int)> rec = [&] (vi partition, int sum, int tot_ct) {
        // cout << "partition: ";
        // for(int i : partition) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // debug(sz(partition) - 1 + tot_ct);
        if (tot_ct > n) return;
        if (sum == k) {
            done = true;
            // int front = n - (sz(partition) - 1 + tot_ct);
            // debug(front);
            // if (sz(partition) == 0) {
            //     for(int i = 0; i < n; i++) ans[i] = n - i;
            //     return;
            // }
            // cout << "partition: ";
            // for(int i : partition) {
            //     cout << i << " ";
            // }
            // cout << endl;
            // int left = 1;
            int right = n;
            int i = 0;
            // while(front > 0) {
            //     ans[i] = right;
            //     right--;
            //     i++;
            //     front--;
            // }
            for(int len : partition) {
                for(int j = 0; j < len; j++) {
                    ans[i] = right - len + 1 + j;
                    i++;
                }
                right -= len;
                // if (i < n) {
                //     ans[i] = right;
                //     right--;
                //     i++;
                // }
            }
            while (right >= 1) {
                ans[i] = right;
                i++;
                right--;
            }
            // while(right >= left) {
            //     ans[i] = right;
            //     right--;
            //     i++;
            // }
        }
        int len = 2;
        // debug(n);
        // debug(tot_ct);
        // debug(len);
        // debug(n - (tot_ct + len));
        // debug((n - (tot_ct + len)) * (n - (tot_ct + len) - 1) / 2);
        // debug(k);
        // debug(k - (sum + len * (len - 1) / 2));
        while ((n - (tot_ct + len)) * (n - (tot_ct + len) - 1) / 2 < k - (sum + len * (len - 1) / 2)) {
            len++;  // need for efficiency/precluding invalid solutions
        }
        while (sum + len * (len - 1) / 2 <= k && tot_ct + len <= n) {
            // debug(len);
            vi new_p = partition;
            new_p.push_back(len);
            rec(new_p, sum + len * (len - 1) / 2, len + tot_ct);
            if (done) return;
            len++;
        }
    };

    rec(vi{}, 0, 0);

    if (done) {
        for(int v : ans) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << 0 << endl;
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
