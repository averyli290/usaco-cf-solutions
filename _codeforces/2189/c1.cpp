

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
const long long INF = 1e18;


void solve() {
    int n ;cin >> n;
    vi ans(n + 1);
    if (n % 2 == 0) {
        for(int i = 1; i <= n; i++) {
            if (i % 2 == 0) ans[i] = i + 1;
            else ans[i] = i - 1;
        }
        ans[1] = n;
        ans[n] = 1;
    } else {
        for(int i = 1; i <= n; i++) {
            if (i % 2 == 0) ans[i] = i + 1;
            else ans[i] = i - 1;
        }
        ans[n] = n;
        ans[n - 1] = 1;
        ans[1] = n - 1;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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
