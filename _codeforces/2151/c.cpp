/*
Problem link: https://codeforces.com/contest/2151/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;


/*

want k as much as possible

*/
void solve() {
    int n; cin >> n;
    vector<ll> a(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    vector<ll> odds;
    vector<ll> evens;
    for (int i = 1; i < 2*n; i++) {
        if(i % 2 == 0) {
            odds.push_back(a[i] - a[i - 1]);
        } else {
            evens.push_back(a[i] - a[i - 1]);
        }
        //cout << a[i] - a[i - 1] << endl;
    }

    vector<ll> oddspref(sz(odds) + 1);
    oddspref[0] = 0LL;
    vector<ll> evenspref(sz(evens) + 1);
    evenspref[0] = 0LL;
    for(int i = 1; i < sz(odds) + 1; i++) {
        oddspref[i] = odds[i - 1] + oddspref[i - 1];
    }
    for(int i = 1; i < sz(evens) + 1; i++) {
        evenspref[i] = evens[i - 1] + evenspref[i - 1];
    }
    ll ans = evenspref[sz(evenspref) - 1] - evenspref[0];
    ll ctr = 0LL;
    // for(ll v : evenspref) {
    //     cout << v << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= n; i++) {
        ll curans = ans;
        cout << ans << " ";
        if (i % 2 == 1) {
            ans += 2 * (oddspref[sz(oddspref) - ctr - 1] - oddspref[ctr]);
            ctr++;
        } else {
            ans += 2 * (evenspref[sz(evenspref) - ctr - 1] - evenspref[ctr]);
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}