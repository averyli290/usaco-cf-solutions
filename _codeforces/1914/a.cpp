/*
Problem link: https://codeforces.com/contest/1914/problem/A
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
    int n; cin >> n;
    string s; cin >> s;
    vector<bool> used(26, false);
    vector<int> ct(26, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ct[s[i] - 'A']++;
        if (ct[s[i] - 'A'] > s[i] - 'A' && !used[s[i] - 'A']) {
            ans++;
            used[s[i] - 'A'] = true;
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
