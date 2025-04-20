/*
Avery Li
4/19/2025
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/552145/problem/G
*/

#include <bits/stdc++.h>
#include <map>

typedef long long ll;

using namespace std;


void solve() {
    int n; cin >> n;
    ll s = 0;
    vector<int> a(n, 0);
    map<int, int> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
        s += a[i];
    }
    map<int, int> c;
    for(auto&[x, y] : b) {
        c[y]++;
    }

    int left = 0;
    int right = n;
    int ans = n;
    int cur = b.size();

    // there are y=c[x] elements with of count x within array a
    // intially, there are 0 elements on the left and n elements on the right
    // there are cur distinct elements

    for (auto&[x, y] : c) {
        ans = min(ans, left + right - cur * x);     // all elements in right only need to be moved down to cur instead of 0
        left += x * y;      // adjust number of elements on left
        right -= x * y;     // adjust number of elements on right
        cur -= y;           // move y distinct elements (they all have count x)
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
