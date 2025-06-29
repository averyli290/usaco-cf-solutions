/*
Problem link: https://codeforces.com/contest/2111/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, m; cin >> n >> m;

    vector<pii> a(m);

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        a[i] = pii({x/100, x});
    }

    sort(a.begin(), a.end());
    //for (auto p : a) {
    //    cout << p.first << " " << p.second << endl;
    //}

    for(int i = 0; i < n; i++) {
        for(int p = 0; p < 6; p++) {
            if ((p + i) % 2 == 0) {
                cout << a[i / 2].second << " ";
            } else {
                cout << a[a.size() - i / 2 - 1].second << " ";
            }
        }
        cout << endl;
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
