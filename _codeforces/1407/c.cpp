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
check consecutive pair, the acutal value of the minimum will always be the greater of the two values
place that value in the array, and keep the index of the greater value, then check again with another index
repeatedly

1, 8
q(1,2) = 4
q(2,1) = 0

1 3 2
3 2 1
3 1 2

*/

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int res; cin >> res;
    return res; 
}

void solve() {
    int n; cin >> n;
    vi ans(n + 1, 0);
    vector<bool> vis(n + 1, 0);
    int i1 = 1;
    int i2 = 2;
    int ctr = 3;
    for(int i = 0; i < n - 1; i++) {
        int r1 = query(i1, i2);
        int r2 = query(i2, i1);
        int m = max(r1, r2);
        if(r1 == m) {
            ans[i1] = m;
            i1 = ctr;
        } else {
            ans[i2] = m;
            i2 = ctr;
        }
        vis[m] = true;
        ctr++;
    }
    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (i1 <= n) ans[i1] = i;
            else ans[i2] = i;
            break;
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
