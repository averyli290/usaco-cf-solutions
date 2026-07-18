/*
Problem link: https://codeforces.com/contest/2237/problem/C
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
for each idx i which val c, need the number of strings
from then on which have the same remainder
*/

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vi x(n);
    vector<vll> pref(n + 1, vll(3, 0ll));
    int cur = 0;
    for(int i = 0; i < n; i++) {
        x[i] = s[i] - '0';
        pref[i + 1] = pref[i];
        if (x[i] == 1) cur++;
        else cur--;
        cur = (cur + 3) % 3;
        pref[i + 1][cur]++;
    }
    cur = 0;
    ll tot = 0ll;
    for(int i = 0; i < n; i++) {
        cur = (cur + 3) % 3;
        tot += n - i - (pref[n][cur] - pref[i][cur]);
        if (x[i] == 1) cur++;
        else cur--;
    }

    int start = 0;
    for(int i = 1; i < n; i++) {
        if (x[i] == x[i - 1]) {
            //asdlkfj ads;flkj das;lfkj asdklfj
            ll l = i - 1 - start + 1;
            // debug(l);
            if (l % 2 == 0) {   // some other math
                tot -=  2 * (l / 2 * (l / 2 - 1) / 2);
                // debug(2 * (l / 2 * (l / 2 - 1) / 2));
            } else {    // math
                tot -=  (l / 2 * (l / 2 - 1) / 2) +((l + 1) / 2 * ((l + 1) / 2 - 1) / 2)  ;
                // debug((l / 2 * (l / 2 - 1) / 2) +((l + 1) / 2 * ((l + 1) / 2 - 1) / 2));
            }
            start = i;
        }
    }
    if (n - start > 1) {
        ll l = n - 1 - start + 1;
        if (l % 2 == 0) {   // some other math
            tot -=  2 * (l / 2 * (l / 2 - 1) / 2);
        } else {    // math
            tot -=  (l / 2 * (l / 2 - 1) / 2) +((l + 1) / 2 * ((l + 1) / 2 - 1) / 2)  ;
        }
    }
    cout << tot << endl;

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
