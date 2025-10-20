/*
Problem link: https://codeforces.com/contest/2153/problem/C
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
    int n; cin >> n;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        mp[x]++;
    }
    
    vector<ll> evens;
    vector<ll> odds;
    for(auto& [k, v] : mp) {
        if (v % 2 == 0) evens.push_back(k);
        else odds.push_back(k);
    }

    ll check = 0LL;
    ll minodd = LLONG_MAX;
    ll mineven = LLONG_MAX;
    int ctr = 0;
    for(auto& [k, v] : mp) {
        if (v % 2 == 0) {
            mineven = min(mineven, k);
        } else {
            minodd = min(minodd, k);
        }
        check += v / 2 * 2 * k;
        ctr += v / 2 * 2;
    }

    sort(all(odds));
    reverse(all(odds));
    if (sz(odds) > 1) {
        check += odds[0];
        ctr += 1;
    }
    sort(all(evens));
    ll ans1 = 0LL;
    ll ans2 = 0LL;
    //debug(check);
    if (ctr < 2) {
        cout << 0 << endl;
        return;
    }
    if (minodd != LLONG_MAX && check > minodd) {
        int start = sz(odds) > 1 ? 1 : 0;
        for(int i = start; i < sz(odds); i++) {
            if (check > odds[i]) {
                ans1 = check + odds[i];
                break;
            }
        }
    }
    if (check - 2 * mineven > mineven) {
        ans2 = check - mineven;
    }
    // debug(ans1);
    // debug(ans2);
    cout << max(ans1, ans2) << endl;
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
