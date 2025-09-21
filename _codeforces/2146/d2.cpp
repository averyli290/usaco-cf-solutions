/*
Problem link: https://codeforces.com/contest/2146/problem/D2
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
if power of 2, pick complement

101101

000100
111011

pair better when going UNDER range
*/

void solve() {
    ll l, r; cin >> l >> r;
    if (l == r) {
        cout << l << endl;
        cout << l << endl;
        return;
    }
    int m = (int)ceil(log2(r));
    vll ans(r + 1 - l, -1);
    vector<ll> used(2 * (r + 1 - l), false);
    set<ll> not_used;
    for(ll i = r; i >= l; i--) not_used.insert(i);
    for(ll i = r; i >= l; i--) {
        ll cur = 1;
        ll val = 0;
        for(ll j = 0; j < m; j++) {        // complement
            if (((i >> j) & 0b1) == 0b0) {
                val += cur;
            }
            cur *= 2;
        }
        if (val > r) {      // set val to smaller if needed while keeping ones and zeroes within bound
            val -= 1 << (m - 1);
        }
        if (val < l) {
            val += 1 << (m - 1);
        }

        bool works = true;
        if (val < l || val >= r) works = false;
        if (val >= l && val <= r) {
            while(used[val - l] || val > r) {      // remove 1's until works? greedy keep the highest values
                int pos;
                if (val <= r) {
                    pos = 63 - __builtin_clz(val);
                } else {
                    pos = 63 - __builtin_clz(val - (1 << (m - 1)));
                }
                if (pos == 0) {
                    works = false;
                    break;
                }
                val -= 1 << (pos);
                if (val < l) {
                    works = false;
                    break;
                }
            }
        }
        if (!works) {           // doomge just get a value now
            if (sz(not_used) == 1) {
                val = *not_used.begin() ;
            } else {
                if (not_used.find(val) == not_used.end()) {
                    auto ptr = not_used.rbegin();
                    ptr++;
                    val = *ptr;
                } else {
                    ll temp = val;
                    not_used.erase(temp);
                    auto ptr = not_used.rbegin();
                    ptr++;
                    val = *ptr;
                    not_used.insert(temp);
                }
            }
        }
        not_used.erase(val);
        ans[i - l] = val;
        used[val - l] = true;
    }
    // calc answer
    ll ansval = 0;
    for(ll i = l; i <= r; i++) {
        ansval += i | ans[i - l];
    }
    cout << ansval << endl;
    for(ll i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
