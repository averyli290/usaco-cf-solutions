/*
Problem link: https://codeforces.com/contest/2111/problem/F
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

/*
4/1,6/2,8/3,10/4


can always do:
increase perimeter by 2, increase area by 1

increase perimeter by 0, increase area by 1
     (as long as there exists a x  shape
                                xx      )


build out in L shape, place squares in corners when desired perimeter reached

x
x
x
xxxx

|
v

xy
xy
xyy
xxxx

note squares added in positions with y add 0 perimeter, 1 area
*/

void solve() {
    int p, s; cin >> p >> s;
    int h;// = (((p - 4) / 2) + 1) / 2;
    int w;// = ((p - 4) / 2) - h;
    int g = gcd(p, s);  // divide out by gcd to start at lowest terms
    p /= g;
    s /= g;
    if (p % 2 == 1) {   // make perimeter even
        s *= 2;
        p *= 2;
    }
    //cout << "h " << h << " w " << w << endl;
    int base_s = s;
    int orig_s = s;
    int orig_p = p;
    int scale = 2;
    while (base_s <= 50000) {           // test increasing scales until find valid h and w
        h = (((p - 4) / 2) + 1) / 2;
        w = ((p - 4) / 2) - h;
        s = base_s - (h + w + 1);
        if (s >= 0 && s <= h * w) {
            break;
        }
        p = orig_p * scale;
        base_s = orig_s * scale;
        scale++;
    }
    if (base_s > 50000) {
        cout << -1 << endl;
        return;
    }

    // construct sol
    vector<pii> ans;
    ans.push_back(pii{0,0});        // bot left
    // vertical
    for(int i = 1; i <= h; i++) { ans.push_back(pii{0, i}); }
    // horizontal
    for(int i = 1; i <= w; i++) { ans.push_back(pii{i, 0}); }

    // fill in remaining squares (+1 area, +0 perimeter)
    int x = 1;
    int y = 1;
    s = base_s - (h + w + 1);
    //cout << "s" << s << endl;
    while (s > 0) {
        s--;
        ans.push_back(pii{x,y});
        y++;
        if (y > h) {
            y = 1;
            x++;
        }
    }
    cout << sz(ans) << endl;
    for(pii p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}