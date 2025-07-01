/*
Avery Li
5/1/2025
Problem link: https://codeforces.com/problemset/problem/230/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, s;
    cin >> s >> n;
    vector<pair<int,int>> c(n);
    for(int i = 0; i< n; i++) {
        int a, b;
        cin >> a >> b;
        c[i] = pair<int,int>({a, b});
    }
    sort(c.begin(), c.end(), [](pair<int, int> x, pair<int,int>y) {
        return x.first < y.first;
    });

    for(int i = 0; i < n; i++) {
        if (s <= c[i].first) {
            cout << "NO" << endl;
            return;
        }
        s += c[i].second;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
