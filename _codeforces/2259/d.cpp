/*
Problem link: https://codeforces.com/contest/2259/problem/D
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
    vi a(n);
    int z = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) z++;
    }

    if (z == 1) {
        cout << "NO" << endl;
        return;
    }

    string ans = "";
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (z == 1) {
                ans += 'B';
            } else {
                ans += 'A';
            }
            z--;
        } else {
            ans += 'C';
        }
    }
    cout << "YES" << endl;
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
