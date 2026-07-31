/*
Problem link: https://codeforces.com/contest/2053/problem/B
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
    int n; cin >> n;
    vi l(n), r(n);
    vi singles;
    map<int, int> m;

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] == r[i]) {
            if (m[l[i]] == 0) singles.push_back(l[i]);
            m[l[i]]++;
        }
    }
    sort(all(singles));
    // for(int i : singles) cout << i << " ";
    // cout << endl;
    vi ans(n);
    for(int i = 0; i < n; i++) {
        // debug(i);
        if (l[i] == r[i] && m[l[i]] >= 2) ans[i] = 0;
        else {
            // cout << l[i] << " " << r[i] << endl;
            auto ptr1 = lower_bound(all(singles), l[i]);
            auto ptr2 = lower_bound(all(singles), r[i] + 1);
            ptr2--;
            // debug(ptr2 - ptr1);
            if (l[i] == r[i]) ptr1++;
            if (ptr2 - ptr1 >= r[i] - l[i]) ans[i] = 0;
            else ans[i] = 1;
        }
    }
    for (int v : ans) cout << v;
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
