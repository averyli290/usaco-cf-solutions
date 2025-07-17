/*
Problem link: https://codeforces.com/contest/2118/problem/D
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

enum Dir {
    RIGHT = true,
    LEFT = false,
};

/*
keep set of states pii{light, dir} if exists, cycle
if next light does not exist, done
get next light: check lights in direction in order, if distance % k == d_that - d_cur, then is next light
O(Q * N * N) complexity, checking N lights for next, only N * 2 states possible to enumerate before done
*/

void solve() {
    ll n, k; cin >> n >> k;
    vll p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    sort(all(p));
    vll d(n);
    for(int i=0;i<n;i++) cin >> d[i];
    vector<pll> pd(n);
    for(int i=0;i<n;i++) pd[i] = pll{p[i], d[i]};
    sort(all(pd));

    ll q; cin >> q;
    while(q--) {
        ll a; cin >> a;
        bool dir = RIGHT;
        // get next light
        int curlight = lower_bound(all(p), a) - p.begin();
        // cout << "a: " << a << " start: " << curlight << endl;
        if (curlight >= n) {
            cout << "YES" << endl;
            continue;
        }
        for(int i=curlight;i<n;i++) {
            if ((((pd[i].first - a) % k) + k) % k == ((pd[i].second % k) + k) % k) {
                curlight = i;
                dir = LEFT;
                break;
            }
        }
        // cout << curlight << " " << (((a - pd[curlight].first) % k) + k) % k << " " << ((pd[curlight].second % k) + k) % k << endl;
        if (dir == RIGHT) {
            cout << "YES" << endl;
            continue;
        }
        bool done = false;
        vector<vi> vis = vector<vi>(501, vi(2, 0));
        vis[curlight][LEFT] = true;
        while(!done) {
            if (dir == RIGHT) {
                for(int i=curlight+1;i<n;i++) {
                    if ((((pd[i].first - pd[curlight].first) % k) + k) % k == (((pd[i].second - pd[curlight].second) % k) + k) % k) {
                        curlight = i;
                        dir = LEFT;
                        break;
                    }
                }
                if (dir == RIGHT) {
                    cout << "YES" << endl;
                    done = true;
                }
            } else {
                for(int i=curlight-1;i>=0;i--){
                    if ((((pd[curlight].first - pd[i].first) % k) + k) % k == (((pd[i].second - pd[curlight].second) % k) + k) % k) {
                        curlight = i;
                        dir = RIGHT;
                        break;
                    }
                }
                if (dir == LEFT) {
                    cout << "YES" << endl;
                    done = true;
                }
            }
            if (!done && vis[curlight][dir]) {
                cout << "NO" << endl;// " " << curlight << " " << dir << endl;
                done = true;
            }
            vis[curlight][dir] = true;
        }
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
