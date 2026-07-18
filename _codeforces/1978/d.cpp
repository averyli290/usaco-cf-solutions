/*
Problem link: https://codeforces.com/contest/1978/problem/D
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
    ll c; cin >> c;
    vll a(n), pref(n + 1, 0ll);
    ll maxval = 0ll;
    int maxidx = 0;
    multiset<ll> rem;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ll val = a[i];
        if (i == 0) {
            val += c;
        }
        if (val > maxval) {
            maxval = val;
            maxidx = i;
        }
        rem.insert(a[i]);
        pref[i + 1] = pref[i] + a[i];
    }

    for(int i = 0; i < n; i++) {
        if (i == maxidx) {
            rem.erase(rem.find(a[i]));
            cout << 0 << " ";
        } else {
            int curans = i;     // all before
            ll cur = pref[i + 1] + c;           // WHY DIDN"T THIS SHOW UP AHHHHH
            auto ptr = rem.rbegin();
            while(cur < *ptr) {
                cur += *ptr;
                curans++;
                ptr++;
            }
            cout << curans << " ";
            rem.erase(rem.find(a[i]));
        }
    }
    cout  << endl;

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
