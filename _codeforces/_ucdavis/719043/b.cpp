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
*/

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (s[0] == '#') {
        cout << "NO" << endl;
        return;
    }
    int mval = 0;
    int cur = 0;
    for(int i=0;i<n;i++) {
        if (s[i] == '.') {
            mval = max(mval, cur);
            cur = 0;
        } else {
            cur++;
        }
    }
    mval = max(mval, cur);
    if (mval >= k) cout << "NO" << endl;
    else cout << "YES" << endl;
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
