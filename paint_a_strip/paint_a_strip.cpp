/*
Avery Li
2/26/2025
Problem link:
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;

/*
1
1001
100100001
cur=ceil((next_cur-1+1)/2)
(cur+1) * 2 = next_cur


*/

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;;
        return;
    } else if (2 <= n && n <= 4) {
        cout << 2 << endl;;
        return;
    }
    int ans = 2;
    int cur = 4;
    while (cur < n) {
        cur += 1;
        cur *= 2;
        ans++;
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
