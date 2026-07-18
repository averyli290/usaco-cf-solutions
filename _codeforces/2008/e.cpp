/*
Problem link: https://codeforces.com/problemset/problem/2008/E
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

    function<int(vi, vi)> calc = [&] (vi e, vi o) {
        return (accumulate(all(e), 0) - max(*max_element(all(e)), 0)) + (accumulate(all(o), 0) - max(*max_element(all(o)), 0));
    };

    vi e(26, 0);
    vi o(26, 0);

    for(int i = 0; i < n; i++) {
        if (i % 2 == 1) e[s[i] - 'a']++;
        else o[s[i] - 'a']++;
    }

    if (n % 2 == 0) {
        cout << calc(e, o) << endl;
    } else {
        int ans = INT_MAX;
        vi pe(26, 0);
        vi po(26, 0);
        for(int i = 0; i < n; i++) {
            vi te = e;
            vi to = o;
            if (i % 2 == 1) te[s[i] - 'a']--;
            else to[s[i] - 'a']--;
            for(int i = 0; i < 26; i++) {
                te[i] -= pe[i];
                to[i] -= po[i];
                swap(te[i], to[i]);
                te[i] += pe[i];
                to[i] += po[i];
            }
            ans = min(ans, calc(te, to));

            if (i % 2 == 1) pe[s[i] - 'a']++;
            else po[s[i] - 'a']++;
        }
        cout << ans + 1 << endl;
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
