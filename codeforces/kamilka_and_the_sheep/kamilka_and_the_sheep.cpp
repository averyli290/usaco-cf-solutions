/*
Avery Li
3/29/2025
Problem link: https://codeforces.com/contest/2092/problem/A
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), less<int>());
    cout << a[n - 1] - a[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
