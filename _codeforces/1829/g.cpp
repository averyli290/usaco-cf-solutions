/*
Problem link: https://codeforces.com/contest/1829/problem/G
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

const ll MAXN = 2023ll;
vector<vll> vals;
vector<vll> pref;
vll cols;
vll rows;

void solve() {
    ll n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    // debug(n);
    auto ptr = lower_bound(all(rows), n + 1);
    ll row = ptr - rows.begin() - 1;
    ll col = n - *(upper_bound(all(rows), n) - 1);
    row -= col;
    cout << pref[row + 1][col + 1] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vals.assign(MAXN + 1, vll(MAXN + 1, 0ll));
    pref.assign(MAXN + 1, vll(MAXN + 1, 0ll));
    cols.assign(MAXN + 1, 0ll);
    rows.assign(MAXN + 2, 0ll);
    rows[0] = 1ll;


    for(ll i = 1; i <= MAXN; i++) {
        vals[0][i - 1] = i * (i + 1) / 2;
        cols[i - 1] = i * (i + 1) / 2;
        rows[i] = cols[i - 1] + 1;
    }
    for(ll i = 2; i <= MAXN; i++) {
        ll ctr = i - 1;
        for(ll j = 1; j <= MAXN - i + 1; j++) {
            vals[i - 1][j - 1] = vals[i - 2][j - 1] + ctr;
            ctr++;
        }
    }

    for(ll i = 0; i <= MAXN; i++) {
        for(ll j = 0; j <= MAXN; j++) {
            vals[i][j] = vals[i][j] * vals[i][j];
        }
    }

    for(ll i = 1; i <= MAXN; i++) {
        for(ll j = 1; j <= MAXN; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + vals[i - 1][j - 1];
        }
    }

    // for(int i = 0; i < 10; i++) {
    //     cout << rows[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 10; i++) {
    //     cout << cols[i] << " ";
    // }
    // cout << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
