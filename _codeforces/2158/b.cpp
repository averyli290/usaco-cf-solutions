/*
Problem link: https://codeforces.com/contest/2158/problem/B
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
odd freq always increases by 1
even, want to split odd odd
*/

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    vector<pii> b;
    for(auto& [k, v] : mp) {
        if (v % 2 == 1) ans++;
        else {
            b.push_back({v, k});
        }
    }
    sort(all(b));
    int ct1 = 0;
    int ct2 = 0;
    for(int i = 0; i < sz(b); i++) {
        if (ct1 > ct2) swap(ct1, ct2);
        if ((b[i].first / 2) % 2 == 0) {
            ct2 += b[i].first / 2 - 1;
            ct1 += b[i].first / 2 + 1;
        } else {
            ct1 += b[i].first / 2;
            ct2 += b[i].first / 2;
        }
        // debug(ct1);
        // debug(ct2);
        if (ct1 > n || ct2 > n) {
            break;
        }
        ans += 2;
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
