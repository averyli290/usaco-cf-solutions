/*
Problem link: https://codeforces.com/contest/2267/problem/D
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
they are distinct
segments have no gaps
*/


void solve() {
    int n; cin >> n;

    vi a(n);
    vi idx(n+1, -1);
    for(int i = 0; i< n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    // for(int i = 1; i <= n; i++) cout << idx[i] << " ";
    // cout << endl;
    int ect = (n + 1) / 2;
    int oct = n / 2;
    for(int i = 1; i <= n; i++) {
        if (idx[i] % 2 == 0) ect--;
        else oct--;
        if (abs(ect - oct) > 1){
            // debug(i);
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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
