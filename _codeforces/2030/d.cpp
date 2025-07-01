/*
Problem link: https://codeforces.com/contest/2030/problem/D
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
    int n, q; cin >> n >> q;
    vi p(n, 0);
    for (int i = 0; i < n; i++) { cin >> p[i]; p[i]--; }
    string s; cin >> s;


    // make sure no interval contains a splitting point
    // get all indices where there is an interval containing it

    vi c(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int x = i; int y = p[i];
        if (x < y) swap(x, y);
        if (x != y) {
            c[y] += 1; c[x] -= 1;
        }
    }
    vector<bool> to_check(n, false);
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += c[i];
        if (cur > 0) to_check[i] = true;
    }

    set<int> kms;

    for(int i = 0; i < n - 1; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R') {
            if (to_check[i]) {
                kms.insert(i);
            }
        }
    }


    while (q--) {
        int idx; cin >> idx; idx--;
        s[idx] = s[idx] == 'L' ? 'R' : 'L';
        // cout << "idx " << idx << endl;
        // cout << s << endl;
        char cur_char = s[idx];
        if (cur_char == 'L') {
            if (idx > 0) {
                if (kms.find(idx - 1) != kms.end()) {
                    kms.erase(idx - 1);
                }
            }
            if (s[idx + 1] == 'R') {
                if (to_check[idx]) {
                    kms.insert(idx);
                }
            }
        }
        else if (cur_char == 'R') {
            kms.erase(idx);
            if (s[idx - 1] == 'L') {
                if (to_check[idx - 1]) {
                    kms.insert(idx - 1);
                }
            }
        }
        // cout << "fun set ";
        // for (int i : kms) cout << i << " " ;
        // cout << endl;
        bool good = sz(kms) == 0;
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
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