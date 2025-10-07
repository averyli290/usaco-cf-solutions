/*
Problem link: https://codeforces.com/contest/1984/problem/C2
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
const long long MOD = 998244353;


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> m;
    m[a[0]] += 1LL;
    m[abs(a[0])] += 1LL;
    ll minval = (ll) a[0];
    ll maxval = abs((ll) a[0]);
    for(int i = 1; i < n; i++) {
        ll v1 = abs(minval + a[i]);
        ll v2 = abs(maxval + a[i]);
        ll v3 = minval + a[i];
        ll v4 = maxval + a[i];
        vll temp({v1, v2, v3, v4});
        ll minvaltemp = *min_element(all(temp));
        ll maxvaltemp = *max_element(all(temp));
        map<ll, ll> tempm;
        if (v1 == minvaltemp) {
            tempm[minvaltemp] += m[minval];
            tempm[minvaltemp] %= MOD;
        }
        if (v2 == minvaltemp && minval != maxval) {
            tempm[minvaltemp] += m[maxval];
            tempm[minvaltemp] %= MOD;
        }
        if (v3 == minvaltemp) {
            tempm[minvaltemp] += m[minval];
            tempm[minvaltemp] %= MOD;
        }
        if (v4 == minvaltemp && minval != maxval) {
            tempm[minvaltemp] += m[maxval];
            tempm[minvaltemp] %= MOD;
        }
        if (maxvaltemp != minvaltemp) {
            if (v1 == maxvaltemp) {
                tempm[maxvaltemp] += m[minval];
                tempm[maxvaltemp] %= MOD;
            }
            if (v2 == maxvaltemp && minval != maxval) {
                tempm[maxvaltemp] += m[maxval];
                tempm[maxvaltemp] %= MOD;
            }
            if (v3 == maxvaltemp) {
                tempm[maxvaltemp] += m[minval];
                tempm[maxvaltemp] %= MOD;
            }
            if (v4 == maxvaltemp && minval != maxval) {
                tempm[maxvaltemp] += m[maxval];
                tempm[maxvaltemp] %= MOD;
            }
        }
    
        // debug(minvaltemp);
        // debug(maxvaltemp);
        // debug(tempm[minvaltemp]);
        // debug(tempm[maxvaltemp]);
        // cout << endl;

        minval = minvaltemp;
        maxval = maxvaltemp;
        // debug(minval);
        // debug(maxval);
        m = tempm;
    }
    //cout << maxval << endl;
    cout << m[maxval] << endl;
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
