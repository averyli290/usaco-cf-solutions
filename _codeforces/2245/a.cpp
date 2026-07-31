/*
Problem link: https://codeforces.com/contest/2245/problem/A
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

LLLLRRLRRRRR
*/

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (k > n / 2) cout << -1 << endl;
    else {
        int ans = 0;
        for(int i = 0; i < k; i++) {
            if (s[i] != 'R') ans++;
        }
        for(int i = 0; i < k; i++) {
            if (s[n - i - 1] != 'L') ans++;
        }
        cout << ans << endl;
    }

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
