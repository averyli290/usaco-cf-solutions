/*
Problem link: https://codeforces.com/contest/1986/problem/E
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
sort into buckets based on mod k
cannot make beautiful if two buckets have odd count
sort buckets, to make minimal, pair up closest numbers together, increase
smallest ot 2nd smallest, 3rd to 4th smallest etc.
if there is an odd count bucket, check minimal by checking each case of removing one
element to place in middle of array
too slow to check manually (O(N^2)), so sort and use prefix/suffix sums on adjacent pairs
and check min across those
*/

void solve() {
    ll n, k; cin >> n >> k;

    vll a(n);
    map<ll, vll> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i] % k].push_back(a[i]);
    }

    int oddct = 0;
    for(auto& [m, vec] : mp) {
        if (sz(vec) % 2 == 1) oddct++;
    }
    if (oddct > 1) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    for(auto& [m, vec] : mp) {
        sort(all(vec));
        if (sz(vec) % 2 == 0) {
            for(int i = 0; i < sz(vec); i+= 2) {
                ans += (vec[i + 1] - vec[i]) / k;
            }
        } else {
            ll n2 = sz(vec) / 2;
            vll sum1(n2);
            vll sum2(n2);
            for(int i = 0; i < n2; i++) {
                sum1[i] = (vec[2*i + 1] - vec[2*i]) / k;
            }
            for(int i = 0; i < n2; i++) {
                sum2[i] = (vec[2*i + 2] - vec[2*i+1]) / k;
            }
            vll pref1(n2 + 1, 0), suff2(n2 + 1, 0);
            for(int i = 0; i < n2; i++) {
                pref1[i + 1] = pref1[i] + sum1[i];
            }
            for(int i = n2; i > 0; i--) {
                suff2[i - 1] = suff2[i] + sum2[i - 1];
            }
            ll curans = LLONG_MAX;
            for(int i = 0; i < n2 + 1; i++) {
                // debug(pref1[i]);
                // debug(suff2[i]);
                curans = min(curans, pref1[i] + suff2[i]);
            }
            ans += curans;
        }
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
