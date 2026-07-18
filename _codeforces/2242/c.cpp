/*
Problem link: https://codeforces.com/contest/2242/problem/C
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


void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    map<int, int> mp;
    int tot = n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    // get below or eq to k
    int lo = 0;
    int hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        bool good = false;
        int totmin = 0;
        for(auto [k, v] : mp) {
            totmin += min(mid, v);
        }
        if (n - totmin <= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    // cout << hi<< endl;

    map<int, int> mp2;
    int curtot = 0;
    for(auto &[k, v] : mp) {
        int newv = v - hi;
        if (newv > 0) {
            mp2[k] = newv;
            curtot += newv;
        }
    }
    mp = mp2;

    int minval = n;
    for(auto[k,v] : mp) {
        minval = min(v, minval);
    }

    int ans = 0;
    while(sz(mp) > 0) {
        if ((k - curtot) % sz(mp) == 0) ans++;
        curtot = 0;

        map<int, int> mp2;
        int newminval = n;
        for(auto &[k, v] : mp) {
            int newv = v - minval;
            if (newv > 0) {
                mp2[k] = newv;
                newminval = min(newv, newminval);
                curtot += newv;
            }
        }
        minval = newminval;
        mp = mp2;
    }
    cout << ans << endl;

    // for(auto &[k, v] : mp2) {
    //     cout << k << " " << v << endl;
    // }
    // cout << endl;
    // return;

    // while(tot > k) {
    //     tot -= sz(mp);
    // }

    // // sort by freqs now and calc off that

    // while (sz(a) > k) {
    //     vi idxs;
    //     idxs.push_back(0);
    //     for(int i = 0; i < n; i++) {
    //         if (a[i])
    //     }
    // }

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
