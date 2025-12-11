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


void solve() {
    int n;
    cin >> n;
    vi a(2*n);
    map<int, int> mp;
    set<int> odds;
    for(int i = 0; i < 2*n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pii> odd;
    vector<pii> even;
    for(auto [k, v] : mp) {
        if (v % 2 == 1) odd.push_back({v, k});
        else even.push_back({v, k});
    }
    sort(all(odd));
    sort(all(even));
    reverse(all(even));
    int ct = n;
    int ans = 0;
    for(auto& [v, k] : even) {
        if (ct == 0) break;
        int to_add;
        if (ct % 2 == 0) {
            to_add = min(ct - 1, v - 1);
        } else {
            to_add = min(ct, v - 1);
        }
        if(to_add > 0 % to_add % 2 == 1) {
            ans+=2;
        }
        v -= to_add;
        ct -= to_add;
    }
    for(auto& [v, k] : odd) {
        if(ct == 0) break;
        ct -= min(ct, v);
    }
    sort(all(even));
    reverse(all(even));
    for(auto& [v, k] : even) {
        if (ct == 0) break;
        int to_add = min(ct, v);
        ct -= to_add;
        ans -= 2;
    }

    cout << ans + sz(odd) << endl;
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
