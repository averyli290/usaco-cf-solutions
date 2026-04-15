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
2 3 6
prevt = 6
2 2 6
prevt = 5
2 1 6
prevt = 5
*/

ll query2(ll idx, ll time) {
    if (time <= 1) {
        return idx;
    }
    ll prevt = 2 * (idx + time) / 3;
    // account for off by ones
    if (prevt % 2 == 0 && idx + time - prevt > prevt / 2) {
        prevt++;
    }
    // debug(prevt);
    if (prevt % 2 == 0) {
        return query2(0LL, prevt-1);
    } else {
        // debug(idx);
        if (idx + (time - prevt) == prevt / 2 + 1) {
            return idx + (time - prevt);
        } else {
            return query2(idx=0, prevt-1);
        }
    }
    return 0LL;
}

ll query1(ll cow, ll time) {
    if (2 * cow > time) return cow;
    ll pos = cow;
    ll curtime = cow * 2 - 1;
    while (true) {
        // debug(curtime);
        // debug(pos);
        if (curtime + pos >= time) {
            return pos - (time - curtime);
        } else {
            curtime += pos + 1;
            pos = curtime / 2;
        }
    }
    return pos;
    // ll time_diff = time - (2 * cow - 1);
    // if (time_diff < 0) {
    //     return cow;
    // }

    // ll k = 1;
    // while (k * cow + (k * (k - 1)) / 2 <= time_diff) k++;
    // k--;
    // debug(k);
    // ll startidx = cow + k;
    // debug(startidx);
    // ll tot_before = k * cow + (k * (k - 1)) / 2;
    // debug(time_diff);
    // debug(tot_before);
    // // time_diff -= tot_before;
    // startidx -= (time_diff - tot_before);
    // return startidx;

}

void solve() {
    int q; cin >> q;
    while(q--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            // cow b introduced at time b
            // doesn't start moving until time 2b
            // moves b+1, then b+2, ...
            // time_diff = c - 2 * b
            // time_diff <= k * b + (0 + 1 + ... + k)
            // time_diff <= k * b + (k * (k + 1)) / 2
            cout << query1(b, c) << endl;
        } else {
            if (b > c / 2) {
                cout << b << endl;
            } else {
                // on the middle or before the middle means it loops
                // b + (t - prevt) = prevt / 2 or (prevt + 1) / 2
                // b + (t - prevt) = prevt / 2
                // b + t = prevt + prevt / 2
                // 3/2(b + t) = prevt
                // if prevt % 2 == 0 (odd amt of cows)
                //      return query2(idx=0, time=prevt-1)
                // if prevt % 2 == 1 (even amt of cows)
                //      if idx == prevt / 2
                //          return idx
                //      else 
                //          return query2(idx=0 time=prevt-1)
                cout << query2(b, c) << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    
}
