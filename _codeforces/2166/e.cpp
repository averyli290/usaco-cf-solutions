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
00001
00100
00101

1010

11110

>>> bin(9)
'0b1001'
>>> bin(5)
'0b0101'
>>> bin(7)
'0b0111'


>>> bin(30)
'0b11110'
>>> bin(1)
'0b00001'
>>> bin(4)
'0b00100'  + 4
>>> bin(5)
'0b00101' + 11
*/


void solve() {
    int n, q;
    cin >> n >> q;
    //vll greatest(32, 0LL);        // greatest[j] = greatest number with msb at j
    vector<vector<tuple<ll, int>>> greatest(32, vector<tuple<ll, int>>{});
    vll a(n);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = x;
        for(int j = 0; j < 30; j++) {
            greatest[j].push_back(tuple<ll,int>{x & ((1 << (j + 1)) - 1), i});
            // cout << (x & ((1 << (j + 1)) - 1)) << endl;
        }
    }
    for(int i = 0; i < 32; i++) {
        //greatest[i].push_back(tuple<ll,int>{0LL, -1});
        sort(all(greatest[i]));
        reverse(all(greatest[i]));
    }

    while(q--) {
        vi used(n, false);
        ll ans = 0LL;
        ll c; cin >> c;
        bool no_inc = false;
        set<ll> not_used(all(a));
        for(int i = 30; i >= 0; i--) {
            if (no_inc) break;
            if ((c >> i) & 0b1 == 0b1) {
                ll cur = 1 << i;
                int to_use = -1;
                bool done = false;
                for(int j = 0; j < sz(greatest[i]); j++) {
                    int idx = get<1>(greatest[i][j]);
                    bool used_val = used[get<1>(greatest[i][j])];
                    ll val = get<0>(greatest[i][j]);
                    if (!used_val && val >= (1 << i)) {
                        done = true;
                        break;
                    }
                }
                if (done) {
                    continue;
                }
                for(int j = i - 1; j >= 0; j--) {
                    if (to_use > -1) break;
                    for(int k = 0; k < sz(greatest[j]); k++) {
                        tuple<ll, int> tmp = greatest[j][k];
                        ll val = get<0>(tmp);
                        int idx = get<1>(tmp);
                        if (!used[idx] && cur > (1 << i) - val) {
                            to_use = idx;
                            cur = (1 << i) - val;
                        }
                    }
                }
                if (to_use != -1) {
                    used[to_use] = true;
                    not_used.erase(a[to_use]);
                }
                ans += cur;
            } else {
                auto ptr = lower_bound(all(not_used), (0b1 << i));
                if (ptr != not_used.end()) {
                    no_inc = true;
                }
            }
        }
        cout << ans << endl;
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
