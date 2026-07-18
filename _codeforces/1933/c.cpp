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
    int a, b, l; cin >> a >> b >> l;

    vi pa;
    vi pb;
    int cur = 1;
    while(cur <= l) {
        pa.push_back(cur);
        cur *= a;
    }
    cur = 1;
    while(cur <= l) {
        pb.push_back(cur);
        cur *= b;
    }

    function<bool(int)> check = [&] (int k) {
        for(int x : pa) {
            for(int y : pb) {
                if (x * y == l / k) {
                    return true;
                }
            }
        }
        return false;
    };

    int ans = 0;
    for(int k = 1; k * k <= l; k++) {
        if(l % k == 0) {
            ans += check(k);
            // if (check(k)) debug(k);
            if (k * k != l) {
                ans += check(l / k);
            }
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
