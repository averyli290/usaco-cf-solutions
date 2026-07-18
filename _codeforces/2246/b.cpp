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

/*
4|7+x
x|7+x
7|7+x

*/

void solve() {
    int n; cin >> n;

    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    vll ans({2,4,6});
    for(int i = 3; i < n; i++) {
        ans.push_back(ans.back() * 2);
    }
    ll s = accumulate(all(ans), 0ll);
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    // cout << s << endl;
    // for(int i = 0; i < n; i++) {
    //     assert(s % ans[i] == 0);
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
