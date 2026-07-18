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
    int n; cin >> n;
    string s; cin >> s;
    reverse(all(s));

    int i = 0;
    string ans = "";
    while(i < n - 3) {
        if ((s[i + 1] == 'a' ||s[i + 1] == 'e' ) && (s[i + 2] == 'b' || s[i + 2] == 'c' || s[i + 2] == 'd')) {
            ans += s[i];
            ans += s[i + 1];
            ans += s[i + 2];
            i += 3;
        } else {
            ans += s[i];
            ans += s[i + 1];
            i += 2;
        }
        ans += '.';
    }
    while (i < n) {
        ans += s[i];
        i++;
    }
    reverse(all(ans));
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
