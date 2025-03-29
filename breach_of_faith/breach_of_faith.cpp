/*
Avery Li
3/27/2025
Problem link: https://codeforces.com/contest/2078/problem/C
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> arr(2 * n, 0);
    ll s = 0;
    for(int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    vector<ll> odds(n + 1, 0);
    vector<ll> evens(n, 0);
    
    for(int i = 0; i < 2 * n; i++) {
        if (i < n + 1) {
            s += arr[i];
            odds[i] = arr[i];
        } else {
            s -= arr[i];
            evens[i - n - 1] = arr[i];
        }
    }
    evens[n - 1] = s;
    for(int i = 0; i < n; i++) {
        cout << odds[i] << " " << evens[i] << " ";
    }
    cout << odds[n];
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
