/*
Problem link: https://codeforces.com/contest/2232/problem/D
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

struct tiii {
    int a;
    int b;
    int c;
};

int n;

bool done;
vector<tiii> f(vi x, vi y, vi z, vi& a, vector<tiii> ops) {
    if(sz(ops) > (1 << n)) return vector<tiii>{};
    int sx = sz(x);
    int sy = sz(y);
    int sz = sz(z);
    int tx = (sx == 0) ? 30 : x[sx - 1];
    int ty = (sy == 0) ? 30 : y[sy - 1];
    int tz = (sz == 0) ? 30 : z[sz - 1];
    if (sx == 0 && sy == 0) {
        done = true;
        return ops;
    }

    for(int i = 0; i < sx; i++) {
        int num_above = sx - i - 1;
        if (a[x[i]] == num_above) {
            if (x[i] < ty) {
                vi tempx = x;
                vi tempy = y;
                vi tempz = z;
                tempx.erase(tempx.begin() + i);
                tempy.push_back(x[i]);
                vector<tiii> tempops = ops;
                tempops.push_back({x[i], 1, 2});
                vector<tiii> ret = f(tempx, tempy, tempz, a, tempops);
                if (done) return ret;
            }
            if (x[i] < tz) {
                vi tempx = x;
                vi tempy = y;
                vi tempz = z;
                tempx.erase(tempx.begin() + i);
                tempz.push_back(x[i]);
                vector<tiii> tempops = ops;
                tempops.push_back({x[i], 1, 3});
                vector<tiii> ret = f(tempx, tempy, tempz, a, tempops);
                if (done) return ret;
            }
        }
    }

    for(int i = 0; i < sy; i++) {
        int num_above = sy - i - 1;
        if (a[y[i]] == num_above) {
            if (y[i] < tx) {
                vi tempx = x;
                vi tempy = y;
                vi tempz = z;
                tempy.erase(tempy.begin() + i);
                tempx.push_back(y[i]);
                vector<tiii> tempops = ops;
                tempops.push_back({y[i], 2, 1});
                vector<tiii> ret = f(tempx, tempy, tempz, a, tempops);
                if (done) return ret;
            }
            if (y[i] < tz) {
                vi tempx = x;
                vi tempy = y;
                vi tempz = z;
                tempy.erase(tempy.begin() + i);
                tempz.push_back(y[i]);
                vector<tiii> tempops = ops;
                tempops.push_back({y[i], 2, 3});
                vector<tiii> ret = f(tempx, tempy, tempz, a, tempops);
                if (done) return ret;
            }
        }
    }
    for(int i = 0; i < sz; i++) {
        int num_above = sz - i - 1;
        if (a[z[i]] == num_above) {
            if (z[i] < ty) {
                vi tempx = x;
                vi tempy = y;
                vi tempz = z;
                tempz.erase(tempz.begin() + i);
                tempy.push_back(z[i]);
                vector<tiii> tempops = ops;
                tempops.push_back({z[i], 3, 2});
                vector<tiii> ret = f(tempx, tempy, tempz, a, tempops);
                if (done) return ret;
            }
            if (z[i] < tx) {
                vi tempx = x;
                vi tempy = y;
                vi tempz = z;
                tempz.erase(tempz.begin() + i);
                tempx.push_back(z[i]);
                vector<tiii> tempops = ops;
                tempops.push_back({z[i], 3, 1});
                vector<tiii> ret = f(tempx, tempy, tempz, a, tempops);
                if (done) return ret;
            }
        }
    }
    return vector<tiii>{};
}


void solve() {
    cin >> n;
    done = false;
    vi a(n + 1);
    vi start;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        start.push_back(i);
    }
    reverse(all(start));
    vector<tiii> ans = f(start, vi{}, vi{}, a, vector<tiii>{});
    if (!done) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << sz(ans) << endl;
    for(int i = 0; i < sz(ans); i++) {
        cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
    }
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
