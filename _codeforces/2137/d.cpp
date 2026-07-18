/*
Problem link: https://codeforces.com/contest/2137/problem/D
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
    vi b(n);
    map<int, int> mp;
    for(int i = 0;i < n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    int tot = 0;
    for(auto [k, v] : mp) {
        if (v % k != 0) {
            cout << -1 << endl;
            return;
        }
    }
    vi conv(n + 1, 0);
    int ctr = 1;
    for(int i = 0; i < n; i++) {
        if (conv[b[i]] == 0) {
            conv[b[i]] = ctr;
            ctr++;
        }
        cout << conv[b[i]] << " ";
        mp[b[i]]--;
        if (mp[b[i]] > 0 && mp[b[i]] % b[i] == 0) {
            conv[b[i]] = ctr;
            ctr++;
        }
    }
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
