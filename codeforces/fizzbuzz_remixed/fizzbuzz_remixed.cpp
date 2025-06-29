/*
Avery Li
2/27/2025
Problem link: https://codeforces.com/contest/2070/problem/A
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;

#include <vector>

/*

*/

using namespace std;

void solve() {
    int n; cin >> n;
    int total = 0;
    vector<int> v = vector<int>(15, 0);
    for (int i = 0; i < 15; i++) {

        if (i % 3 == i % 5){
            total++;
        }
        v[i] = total;
    }

    cout << (n / 15) * total + (v[n % 15])<< endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

}
