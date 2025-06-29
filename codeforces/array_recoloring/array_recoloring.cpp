/*
Avery Li
3/17/2025
Problem link: https://codeforces.com/contest/2075/problem/B
*/

#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;


using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n, 0);
    for (int i =0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int s = 0;
    int i = 0;
    while (i < k + 1 && i < n) {
        s += v[i];
        i++;
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
