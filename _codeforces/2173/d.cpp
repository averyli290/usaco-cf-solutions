/*
Problem link: https://codeforces.com/contest/2173/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
000010010
000010110
000011110
000100000

000010010
000010100
000011000
000100000

nvm naive greedy doesn't work this solution is wrong
maybe add some brute force over the greedy
*/

void solve() {
    ll n, k; cin >> n >> k;

    vector<piii> groups;
    vi v(64, 0);
    vi vh(64, 0);

    int last = -1;
    for(int i = 0; i < 32; i++) {
        if (((n >> i) & 0b1) == 0b1) {
            if (last == -1) last = i;
        } else {
            if (last != -1) {
                groups.push_back({i - last, -last, 0});
                last = -1;
            }
        }
        v[i] = ((n >> i) & 0b1);
    }

    priority_queue<piii> pq(all(groups));

    ll ans = 0;

    int curhnum = 0;
    while(!pq.empty() && k > 0) {
        auto [count, idx, hnum] = pq.top();
        idx= -idx;
        pq.pop();
        ans += count;
        // debug(idx);

        if(hnum < vh[idx]) continue;
        while(v[idx] == 1) {
            idx++;
            vh[idx] = curhnum;
        }
        int newcount = 1;
        while(v[idx + newcount] == 1) newcount++;
        pq.push({newcount, -idx, curhnum});

        k--;

        // if (pq.empty()) {
        //     // compute separately
        // }
        curhnum++;
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
