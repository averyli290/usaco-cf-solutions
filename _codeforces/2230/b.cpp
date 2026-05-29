/*
Problem link: https://codeforces.com/contest/2230/problem/B
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
no 0, 4, 8
no 1, 3, 5, 7, 9 before 2 or 6
put all 2's and 6's before 1,3,5,7,9
*/


void solve() {
    string s; cin >> s;
    int n = s.length();
    vi pref(n + 1, 0);
    vi suff(n + 1, 0);
    int ct = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '4' || s[i] == '8') ct++;
    }

    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        if (
            s[i] == '1' ||
            s[i] == '3' ||
            s[i] == '5' ||
            s[i] == '7' ||
            s[i] == '9'
        ) {
            pref[i + 1]++;
        }
    }
    for(int i = n; i > 0; i--) {
        suff[i - 1] = suff[i];
        if (
            s[i] == '2' ||
            s[i] == '6'
        ) {
            suff[i - 1]++;
        }
    }
    int ans = n;
    for(int i = 0; i < n; i++) {
        // remove all 2's and 6's including and after this point
        int after = suff[i];

        // remove all odds before not including this point
        int before = pref[i];

        ans = min(after + before, ans);
    }

    cout << ans + ct << endl;
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
