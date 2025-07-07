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
const long long INF = 1e18;


void solve() {
    int n, m; cin >> n >> m;
    int k = n - m;
    multiset<int> a;
    priority_queue<int> b;
    for(int i = 0 ; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for(int i = 0 ; i < m; i++) {
        int x; cin >> x;
        b.push(-x);
    }
    while (sz(a) > 0) {
        int cur = -1 * b.top(); b.pop();
        auto ptr = a.find(cur);
        if (ptr != a.end()) {
            a.erase(ptr);
        } else {
            if (k == 0) {
                cout << "NO" << endl;
                return;
            }
            b.push(-cur/2);
            b.push(-(cur+1)/2);
            k--;
        }
        cout << k << endl;
    }

    if(sz(a) == 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}