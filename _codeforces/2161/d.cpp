/*
Problem link:
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

sort

on adjacents, remove odds or remove evens?

taking all of the next ones out means that some will not have to 

a, a+1, a+2
taking all of next a+1 out means that some of a+2 wont need to be taken out

dp on the set of values in array
at index i:
dp[x][0] = # of ways to make good array with other x's still remaining in array
dp[x][1] = # of ways to make good array with all x's removed from array
*/

void solve() {
    int n; cin >> n;
    vi a(n);
    map<int, int> mp;
    set<int> b;
    map<int, int> maxindex;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        b.insert(x);
        mp[x]++;
        a[i] = x;
        maxindex[x] = i;
    }

    map<int, array<int, 2>> dp;
    for(int i = 0; i < n; i++) {
        dp[a[i]][0] = 1000000;
        dp[a[i]][1] = 1000000;
    }
    dp[a[0]][0] = 0;        // valid at start
    dp[a[0]][1] = 1000000;        // remove is also valid
    int ans = 0;

    for(int i = 0; i < n; i++) {
        // cout << "before: " << dp[a[i]][0] << " "<< dp[a[i]][1] << endl;
        if (maxindex.count(a[i] + 1) > 0 && i < maxindex[a[i] + 1]) {
            // need to check, if keeping cur, that you take max(dp[a[i][0]], dp[a[i] - 1][1])
            // because cannot keep unless everything before is gone

            // keep cur, remove all future a[i] + 1
            int temp = dp[a[i]][0] + mp[a[i] + 1];
            if (dp.count(a[i] - 1) > 0 && dp[a[i] - 1][1] > dp[a[i]][0]) {
                temp = dp[a[i] - 1][1] + mp[a[i] + 1];
            }
            // remove cur
            if (i == maxindex[a[i] + 1]) {
                dp[a[i]][0] += 1;
                dp[a[i]][1] += 1;
            } else {
                dp[a[i]][0] += 1;
            }
            dp[a[i] + 1][1] = min(dp[a[i] + 1][1], temp);
            dp[a[i]][0] = min(dp[a[i]][0], temp);
            dp[a[i + 1]][0] = min(dp[a[i]][1], dp[a[i]][0]);
        } else {
            // propogate next val
            if (i < n - 1) dp[a[i + 1]][0] = min(dp[a[i]][1], dp[a[i]][0]);
        }
        // debug(a[i]);
        // cout << "after: " << dp[a[i]][0] << " "<< dp[a[i]][1] << endl;
        mp[a[i]]--; // update freq
    }
    // if (sz(a) != start) {
    //     oddsum += mp[a[start]];
    //     ans += min(evensum, oddsum);
    // }
    cout << min(dp[a[n - 1]][0], dp[a[n-1]][1]) << endl;
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
