/*
Problem link: https://codeforces.com/contest/1920/problem/C
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

int gcddiff(vi& t) {
    assert(sz(t) >= 2);
    int ans = -1;
    for(int i = 1; i< sz(t); i++) {
        if (ans == -1) ans = abs(t[i] - t[i - 1]);
        else ans = gcd(ans, abs(t[i] - t[i - 1]));
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++)  {
        cin >> a[i];
    }

    int ans = 1;

    for(int f = 1; f < n; f++) {
        if (n % f != 0)  continue;
        if (f == 1) {
            if (gcddiff(a) != 1) ans++;
        } else {
            int gg = -1;
            for(int start = 0; start < f; start++) {
                vi nums;
                for(int jump = 0; jump < n / f; jump++) {
                    int idx = jump * f + start;
                    nums.push_back(a[idx]);
                }
                int g = gcddiff(nums);
                if (g != 0) {
                    if (gg == -1) gg = g;
                    else gg = gcd(gg, g);
                }
            }
            if (gg > 1 || gg == -1) ans++;
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