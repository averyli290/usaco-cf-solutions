/*
Problem link: https://atcoder.jp/contests/abc439/tasks/abc439_d
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
exclude 3,5,7 and 7,5,3
*/

void solve() {
    int n; cin >> n;
    vi a;
    ll ct = 0ll;
    ll n3 = 0ll;
    ll n5 = 0ll;
    ll n7 = 0ll;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 3 || x ==5 || x == 7) {
            a.push_back(x);
            ct++;
        }
        if (x == 3) n3++;
        if (x == 5) n5++;
        if (x == 7) n7++;
    }
    // 3 5 7
    n = sz(a);
    vll suff7(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff7[i] = suff7[i + 1] + ((a[i] == 7) ? 1ll : 0ll);
    }
    vll suff57(n + 1, 0ll);
    vll suff37(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff57[i] = suff57[i + 1] + ((a[i] == 5) ? suff7[i + 1] : 0ll);
        suff37[i] = suff37[i + 1] + ((a[i] == 3) ? suff7[i + 1] : 0ll);
    }
    vll suff357(n + 1, 0ll);
    vll suff537(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff357[i] = suff357[i + 1] + ((a[i] == 3) ? suff57[i + 1] : 0ll);
        suff537[i] = suff537[i + 1] + ((a[i] == 5) ? suff37[i + 1] : 0ll);
    }


    // 7 5 3
    vll suff3(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff3[i] = suff3[i + 1] + ((a[i] == 3) ? 1ll : 0ll);
    }
    vll suff53(n + 1, 0ll);
    vll suff73(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff53[i] = suff53[i + 1] + ((a[i] == 5) ? suff3[i + 1] : 0ll);
        suff73[i] = suff73[i + 1] + ((a[i] == 7) ? suff3[i + 1] : 0ll);
    }
    vll suff753(n + 1, 0ll);
    vll suff573(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff753[i] = suff753[i + 1] + ((a[i] == 7) ? suff53[i + 1] : 0ll);
        suff573[i] = suff573[i + 1] + ((a[i] == 5) ? suff73[i + 1] : 0ll);
    }

    // 7 5 3
    vll suff5(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff5[i] = suff5[i + 1] + ((a[i] == 5) ? 1ll : 0ll);
    }
    vll suff35(n + 1, 0ll);
    vll suff75(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff35[i] = suff35[i + 1] + ((a[i] == 3) ? suff5[i + 1] : 0ll);
        suff75[i] = suff75[i + 1] + ((a[i] == 7) ? suff5[i + 1] : 0ll);
    }
    vll suff735(n + 1, 0ll);
    vll suff375(n + 1, 0ll);
    for(int i = n - 1; i >= 0; i--) {
        suff735[i] = suff735[i + 1] + ((a[i] == 3) ? suff35[i + 1] : 0ll);
        suff375[i] = suff375[i + 1] + ((a[i] == 7) ? suff75[i + 1] : 0ll);
    }

    // tot
    debug(suff357[0]+suff753[0]);
    // cout << (suff735[0]+suff375[0]+suff537[0]+suff573[0])-(suff357[0]+suff753[0]) << endl;
    cout << n3*n5*n7-(suff357[0]+suff753[0]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
