/*
Avery Li
4/27/2025
Problem link: https://codeforces.com/contest/2098/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // check which numbers can be made medians <--------
    // any house within a range between two houses (inclusive) works
    // the range defining the two houses must have the lower house
    // be at least k/2 distance elements above 0 (inclusive) and the upper must
    // be at least k/2 distance elements below n (inclusive)
    // each house individually between lower and upper bound also count
    
    int c = (n - k + 1)/ 2 - 1;
    vector<pair<int, int>> ranges;
    int ans = 0;
    for (int i = c; i < n - c; i++) {
        ranges.push_back(pair<int,int>{a[i], a[i]});
        if (i + 1 < n - c) {
            ranges.push_back(pair<int,int>{a[i], a[i + 1]});
        }
    }

    int r = ranges.size();
    for (int i = 0; i < r; i++) {
        ans += ranges[i].second - ranges[i].first + 1;
        if (i < r - 1 && ranges[i + 1].first <= ranges[i].second) {
            ans -= ranges[i + 1].first - ranges[i].second + 1;
        }
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
