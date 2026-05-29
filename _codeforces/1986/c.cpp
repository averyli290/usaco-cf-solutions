/*
Problem link: https://codeforces.com/contest/1986/problem/B
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi ind(m);
    for(int i = 0; i < m; i++) {
        cin >> ind[i];
        ind[i]--;
    }
    string s2; cin >> s2;
    vector<char> s1;
    for(int i = 0; i < m; i++) s1.push_back(s[i]);
    sort(all(s1));
    vector<char> ans(n, '0');
    for(int i = 0; i < m; i++) {
        ans[ind[i]] = s2[i];
    }
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if (ans[i] == '0') {
            debug(ans[i]);
            ans[i] = s1[idx];
            idx++;
        }
    }
    for(char v : ans) {
        cout << v;
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
