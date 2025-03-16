/*
Avery Li
3/3/2025
Problem link:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a = vector<int>(n,0);
    vector<int> b = vector<int>(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
