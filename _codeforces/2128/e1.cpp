/*
Problem link: https://codeforces.com/contest/2128/problem/E1
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
bs the answer
*/

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    function<pii(int)> check = [&] (int val) {
        // bsta ts you lazy ahhh bum
        // debug(val);
        vi BIG(n, 0), pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            BIG[i] = a[i] >= val ? 1 : -1;      // to remove accounting for length
            pref[i + 1] = pref[i] + BIG[i];
            // cout << pref[i + 1] << " ";
        }
        // cout << endl;

        // maintain leftmost min value at least k left to maximize the amount of larger values
        int minval = pref[0];
        int minidx = 1;
        for(int i = k; i <= n; i++) {
            if (pref[i] - minval >= 0) {
                return pii{minidx, i};
            }
            if (pref[i - k + 1] < minval) {
                minval = pref[i - k + 1];
                minidx = i - k + 1 + 1;
            }
        }
        return pii{-1, -1};
    };
    int lo = 0;
    int hi = n;
    pii ans;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        pii v = check(mid);
        if (v.first > -1) {
            lo = mid;
            ans = v;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << " " << ans.first << " " << ans.second << endl;

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
