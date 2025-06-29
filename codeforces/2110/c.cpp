/*
Problem link: 
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    // keep track of max and min possible height at each step
    int a = 0; // min possible height
    int b = 0; // max possible height
    vector<int> sol(n);
    for (int i = 0; i < n; i++) {
        if (d[i] == -1){
            if (a > r[i] || b < l[i] - 1) {
                cout << -1 << endl; 
                return;
            }
            a = max(a, l[i]);
            b = min(b + 1, r[i]);
        } else if (d[i] == 0) {
            if (a > r[i] || b < l[i]) {
                cout << -1 << endl; 
                return;
            }
            a = max(a, l[i]);
            b = min(b, r[i]);
        } else {
            a++;
            b++;
            if (a > r[i] || b < l[i]) {
                cout << -1 << endl; 
                return;
            }
            a = max(a, l[i]);
            b = min(b, r[i]);
        }
    }
    vector<int> suf(n + 1, INT_MAX);
    for (int i = n - 1 ; i >= 0; i--) {
        suf[i] = min(suf[i + 1], r[i]);
    }
    // sol exists
    int cur_h = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1){
            if (cur_h + 1 <= suf[i]) {
                sol[i] = 1;
                cur_h++;
            } else {
                sol[i] = 0;
            }
        } else {
            sol[i] = d[i];
            cur_h += d[i];
        }
    }

    for(auto v : sol) {
        cout << v << " ";
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
