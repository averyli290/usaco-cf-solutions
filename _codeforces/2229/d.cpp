/*
Problem link: https://codeforces.com/problemset/problem/2229/D
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
count diff between 1's and 0's

cute dog: https://www.youtube.com/watch?v=pNgk76VpyIM
*/


void solve() {
    int n; cin >> n;
    vi a(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    function<bool(int)> check = [&] (int val) {
        vi ta(n), tb(n);
        int diff = 0;
        for(int i = 0; i < n; i++) {
            ta[i] = a[i] >= val ? 1 : 0;
            tb[i] = b[i] >= val ? 1 : 0;
            if (ta[i]) diff++;
            else diff--;
            if (tb[i]) diff++;
            else diff--;
        }
        // debug(diff);
        // debug(val);
        // for(int v : ta) cout << v << " ";
        // cout << endl;
        // for(int v : tb) cout << v << " ";
        // cout << endl;
        int pa = ta[0];
        int pb = tb[0];
        for(int i = 1; i <= n - 1; i++) {
            if (pa + pb + ta[i] + tb[i] == 0) {
                diff += 2;
                pa = 0;
                pb = 0;
            } else if (pa + pb + ta[i] + tb[i] == 1) {
                pa = 0;
                pb = 0;
            } else if (pa + pb + ta[i] + tb[i] == 2) {
                pa = 1;
                pb = 0;
                if (ta[i] == 0 && tb[i] == 0) {
                    pa = 0;
                    pb = 0;
                }
            } else {
                pa = 1;
                pb = 1;
            }
        }
        if (diff > 0) return true;
        return false;
    };
    int lo = 0;
    int hi = 2 * n;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
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
