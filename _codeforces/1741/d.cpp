/*
Problem link: https://codeforces.com/problemset/problem/1741/D
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
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i+=2) {
        if (abs(a[i] - a[i + 1]) != 1) {
            cout << -1 << endl;
            return;
        }
    }

    bool good = true;

    function<array<int, 3>(int,int)> c = [&] (int l, int r) {
        array<int, 3> ret;
        if (r - l == 2) {
            if (a[l] > a[l + 1]) ret = {1, a[l + 1], a[l]};
            else ret = {0, a[l], a[l + 1]};
        } else {
            int mid = (r + l) / 2;
            array<int, 3> ret1 = c(l, mid);
            array<int, 3> ret2 = c(mid, r);
            ret[0] = ret1[0] + ret2[0];
            ret[1] = min(ret1[1], ret2[1]);
            ret[2] = max(ret1[2], ret2[2]);
            if (ret1[2] > ret2[1]) {
                if (ret1[1] - 1 != ret2[2]) good = false;
                ret[0]++;
            } else {
                if (ret1[2] + 1 != ret2[1]) good = false;
            }
        }
        // debug(l);
        // debug(r);
        // debug(ret[0]);
        // debug(ret[1]);
        // debug(ret[2]);
        return ret;
    };

    auto res = c(0,n);
    if(!good) {
        cout << -1 << endl;
        return;
    }
    cout << res[0] << endl;
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
