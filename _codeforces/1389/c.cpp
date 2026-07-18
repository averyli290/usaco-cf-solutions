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
    string s; cin >> s;
    int n = sz(s);
    int ans = n;
    for(int a = 0; a < 10; a++) {
        for(int b = 0; b < 10; b++) {
            int ctr = 0;
            int cur = 0;
            for(int i = 0;i < n;i++) {
                if (ctr % 2 == 0) {
                    if (s[i] - '0' == a) ctr++;
                    else cur++;
                } else {
                    if (s[i] - '0' == b) ctr++;
                    else cur++;
                }
            }
            if (a != b && ctr % 2 == 1) cur++;
            ans = min(ans, cur);
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
