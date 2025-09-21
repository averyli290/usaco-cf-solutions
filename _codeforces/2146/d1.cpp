/*
Problem link: https://codeforces.com/contest/2146/problem/D1
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
 
 
void solve() {
    int l, r; cin >> l >> r;
    if (r == 1) {
        cout << 2 << endl;
        cout << "1 0" << endl;
        return;
    }
    int m = (int)ceil(log2(r));
    vi ans(r + 1, -1);
    vector<bool> used(r + 1, false);
    set<int> not_used;
    for(int i = r; i >= 0; i--) not_used.insert(i);
    for(int i = r; i >= 0; i--) {
        int cur = 1;
        int val = 0;
        for(int j = 0; j < m; j++) {
            if (((i >> j) & 0b1) == 0b0) {
                val += cur;
            }
            cur *= 2;
        }
        if (val > r) {
            val -= 1 << (m - 1);
        }
        bool works = true;
        while(used[val]) {
            int pos = 31 - __builtin_clz(val);
            if (pos == 0) {
                works = false;
                break;
            }
            val -= 1 << (pos);
        }
        if (!works) {
            val = *not_used.begin();
        }
        not_used.erase(val);
        ans[i] = val;
        used[val] = true;
    }
    ll ansval = 0;
    for(int i = 0; i <= r; i++) {
        ansval += i | ans[i];
    }
    cout << ansval << endl;
    for(int i : ans) {
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