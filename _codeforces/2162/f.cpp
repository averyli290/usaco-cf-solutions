/*
Problem link: https://codeforces.com/contest/2162/problem/F
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

0: all intervals intersect, place 0 in the intersection
1: can make all mexes 0 or greater than 1
wherever you place 0, all intervals containing that will also contain 1
iterate over all adjacent indices, check intervals containing those
this happens iff a boundary lies between the indices, it suffices to find adjacent
where they do not have an interval boundary there. Then place 0 there, and then 1
adjacent to the 0 such that all intervals which include the 0 must also include the 1

2: uhhh just place 0 1 and ends and 2 at middle otherwise

*/

void solve() {
    int n, m; cin >> n >> m;

    vi diff(n + 2, 0);
    set<int> lefts;
    set<int> rights;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        lefts.insert(l);
        rights.insert(r);
        diff[l]++;
        diff[r + 1]--;
    }
    vi ct(n, 0);
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cur += diff[i];
        ct[i - 1] = cur;
    }
    // for(int v : ct) {
    //     cout << v << " ";
    // }
    // cout << endl;
    int zero_idx = -1;
    for(int i = 0; i < n; i++) if(ct[i] == m) zero_idx = i;
    // debug(zero_idx);
    vi ans(n, -1);
    // 0
    if (zero_idx > -1) {
        ans[zero_idx] = 0;
        int ctr = 1;
        for(int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = ctr;
                ctr++;
            }
        }
        for(int v : ans) cout << v << " ";
        cout << endl;
        return;
    }

    int one_idx = -1;
    int f = 0;
    for(int i = 0; i < n; i++) {
        if (!(rights.find(i + 1) != rights.end() && lefts.find(i + 1) != lefts.end())) {
            one_idx = i;
            if (rights.find(i + 1) != rights.end()) f = -1;
            else f = 1;
            if (i == 0) f = 1;
            if (i == n - 1) f = -1;
            break;
        }
    }
    // 1
    // debug(one_idx);
    if (one_idx > -1) {
        ans[one_idx] = 0;
        ans[one_idx + f] = 1;
        int ctr = 2;
        for(int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = ctr;
                ctr++;
            }
        }
        for(int v : ans) cout << v << " ";
        cout << endl;
        return;
    }

    // 2
    ans[0] = 0;
    ans[n - 1] = 1;
    int ctr = 2;
    for(int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = ctr;
            ctr++;
        }
    }
    for(int v : ans) cout << v << " ";
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
