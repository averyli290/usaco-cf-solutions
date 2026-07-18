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
https://www.youtube.com/watch?v=9qN9EF-6IcI
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '#') {
            cur++;
        } else {
            // int temp = 0;
            // if (cur % 2 == 0) temp = cur / 2;
            // else temp 
            ans = max(ans, (cur + 1) / 2);
            cur = 0;
        }
    }
    ans = max(ans, (cur + 1) / 2);
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
