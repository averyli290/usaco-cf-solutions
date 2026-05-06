/*
Problem link:
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*

if all r, g, b are equal ct then can apply the following rule for the rest
XYZ -> YXZ or ZXY

let a, b, c be the ct required to make all the remaining cts equal
one of them must be 0, WLOG a, b > 0, a >= b

if a == b, abab...ab
if a >= b, abab...aba + cab + ...



*/

void solve() {
    int r, g, b; cin >> r >> g >> b;
    array<pii, 3> mp;
    mp[0] = {r, 1};
    mp[1] = {g, 2};
    mp[2] = {b, 3};
    sort(all(mp));

    int blocks = mp[0].first;

    int rem2 = mp[1].first - blocks;
    int rem3 = mp[2].first - blocks;
    rem3 = min(rem2 + 1, rem3);

    int aa = mp[0].second;
    int bb = mp[1].second;
    int cc = mp[2].second;

    vi ans;
    int lidx;
    if(rem2 == rem3) {
        // bcbc..cbc
        ans.resize(2 * rem2 + 3 * blocks, 0);
        for(int i = 0; i < 2 * rem2; i+=2) {
            ans[i] = bb;
            ans[i + 1] = cc;
        }
        lidx = 2 * rem2;
    } else {
        // cbc...cbc
        ans.resize(2 * rem2 + 1 + 3 * blocks, 0);
        ans[0] = cc;
        for(int i = 1; i < 2 * rem2 + 1; i+=2) {
            ans[i] = bb;
            ans[i + 1] = cc;
        }
        lidx = 2 * rem2 + 1;
    }

    // bca cab abc
    array<array<int, 3>, 3> p;
    p[0] = {1,2,3};
    p[1] = {2,3,1};
    p[2] = {3,1,2};
    debug(lidx);
    for(int i = 0; i < blocks; i++) {
        ans[lidx + i] = p[i % 3][0];
        ans[lidx + i + 1] = p[i % 3][1];
        ans[lidx + i + 2] = p[i % 3][2];
    }

    for(int i = 0; i < sz(ans); i++) {
        int x = ans[i];
        if(x==1) cout << "R";
        else if(x==2) cout << "G";
        else if(x==3) cout << "B";
    }
    cout << endl;
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
