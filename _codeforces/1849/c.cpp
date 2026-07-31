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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi a, b;
    b.push_back(-1);
    vi inflection;
    for(int i = 0; i < n; i++) {
        if (i < n - 1 && s[i] == '1' && s[i + 1] == '0') {
            inflection.push_back(i);
        }
        if (s[i] == '0') a.push_back(i);
        else b.push_back(i);
    }
    a.push_back(n);

    // for(int v : a) {
    //     cout << v << " ";
    // }
    // cout << endl;

    set<pii> st;
    while(m--) {
        int l, r; cin >> l >> r;

        auto ptr1 = lower_bound(all(inflection), l - 1);
        if (ptr1 == inflection.end() || *ptr1 >= r - 1) {
            st.insert({-1, -1});
            continue;
        }

        l--;
        r--;
        // closest 1 to left
        int newl = *(lower_bound(all(b), l + 1) - 1);
        // debug(newl);
        // closest 0 to right
        int newr = *(upper_bound(all(a), r));
        // debug(r);
        // debug(newr);
        st.insert({newl, newr});

    }
    // for(auto [x, y] : st) {
    //     cout << x << " " << y << endl;
    // }
    cout << sz(st) << endl;

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
