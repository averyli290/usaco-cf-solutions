/*
Avery Li
4/27/2025
Problem link: https://codeforces.com/contest/2098/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    string n; cin >> n;
    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        a[i] = (n[i] - '0');
    }
    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = 9; i >= 0; i--){
        int min_val = INT_MAX;
        int min_ind = -1;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] >= i && a[j] < min_val) {
                min_val = a[j];
                min_ind = j;
            }
        }
        res += min_val;
        res *= 10;
        a.erase(a.begin() + min_ind);
    }
    cout << res / 10 << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
