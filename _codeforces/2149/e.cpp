/*
Problem link: https://codeforces.com/contest/2149/problem/E
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
    int n, l, r, k;
    cin >> n >> k >> l >> r;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> freq1;
    int ct1 = 0;
    map<int, int> freq2;
    int ct2 = 0;
    int hi1 = 0;
    int hi2 = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while (hi1 + 1 < n && ct1 < k) {
            if (freq1[a[hi1 + 1]] == 0) ct1++;
            freq1[a[hi1 + 1]]++;
            hi1++;
        }
        // hi1--;
        while (hi2 < n && ct2 <= k) {
            if (freq2[a[hi2]] == 0) ct2++;
            freq2[a[hi2]]++;
            hi2++;
        }
        // hi2--;
        debug(hi1);
        debug(hi2);
        // ans += hi2 - hi1 + 1;
        ans += max(0, min(hi2 - 1, i + r - 1) - max(hi1, i + l - 1) + 1);
        debug(ans);
        freq1[a[i]]--;
        if (freq1[a[i]] == 0) ct1--;
        freq2[a[i]]--;
        if (freq2[a[i]] == 0) ct2--;
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
