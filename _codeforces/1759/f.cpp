/*
Problem link:
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
    int n, p; cin >> n >> p;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last = a.back();
    // check if need any greater than last
    set<int> s(all(a));

    // if (last == 0) {
    //     int ans = p - 1;
    //     ans -= sz(s) - 1;
    //     cout << ans << endl;
    //     int max_needed = -1;
    //     int cur = p - 1;
    //     for(int i = 0; i < n; i++) {
    //         if (cur <= last) break;
    //         if (s.find(cur) == s.end()) {
    //             max_needed = cur;
    //             break;
    //         }
    //     }
    //     return;
    // }
    // if (last == 1) {

    // }

    int max_needed = -1;
    int cur = p - 1;
    for(int i = 0; i < n; i++) {
        if (cur <= last) break;
        if (s.find(cur) == s.end()) {
            max_needed = cur;
            break;
        }
        cur--;
    }
    int ans = 0;
    // if (max_needed > 0)
    ans += max_needed - last;
    // debug(max_needed);
    // first digit at max_needed

    cur = last - 1;
    while(cur >= 0) {
        if (s.find(cur) == s.end()) break;
        cur--;
    }
    if (cur >= 0) {
        ans += p - max_needed;
        a.insert(a.begin(), 0);
        a[sz(a) - 1] = 0;
        int idx = sz(a) - 1;
        a[sz(a) - 2]++;
        int curidx = sz(a) - 1;
        s.insert(0);
        while(curidx > 0) {
            s.insert(a[curidx]);
            s.insert(a[curidx - 1]);
            if (a[curidx - 1] == p) {
                curidx--;
                a[curidx] = 0;
                if (curidx > 0) {
                    a[curidx]++;
                }
            }
            else {
                curidx--;
            }
        }
        // for(int x : s) {
        //     cout << x << " ";
        // }
        // cout << endl;
        cur = last - 1;
        while(cur >= 0) {
            if (s.find(cur) == s.end()) break;
            cur--;
        }
        if (cur > 0) ans += cur;
    }
    cout << max(0, ans) << endl;
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
