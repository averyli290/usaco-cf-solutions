/*
Problem link: https://codeforces.com/contest/2114/problem/D
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> x;
    set<int> y;
    for(int i = 0; i < n; i++) {
        int tx, ty; cin >> tx >> ty;
        x.insert(tx);
        y.insert(ty);
    }

    vector<int> new_x(x.begin(), x.end());
    vector<int> new_y(y.begin(), y.end());
    sort(new_x.begin(), new_x.end());
    sort(new_y.begin(), new_y.end());


    int diffx = 0;
    int diffy = 0;

    if (new_x.size() >= 2) {
        diffx = max(new_x[1] - new_x[0], new_x[new_x.size() - 1] - new_x[new_x.size() - 2]);
    }
    if (new_y.size() >= 2) {
        diffx = max(new_y[1] - new_y[0], new_y[new_y.size() - 1] - new_y[new_y.size() - 2]);
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
