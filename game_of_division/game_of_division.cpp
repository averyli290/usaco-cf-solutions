/*
Avery Li
2/26/2025
Problem link: https://codeforces.com/contest/2040/problem/A
*/

/*
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
typedef long long ll;


using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a = vector<int>(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        int j = 0;
        bool works = true;
        while (j < n && works) {
            if (i != j && abs(a[i]-a[j]) % k == 0) works = false;
            j++;
        }
        if (works) {
            cout << "YES" << endl << i + 1 << endl;
            return;
        }
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
