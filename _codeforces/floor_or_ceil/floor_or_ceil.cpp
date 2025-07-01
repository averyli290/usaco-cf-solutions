/*
Avery Li
3/15/2025
Problem link: https://codeforces.com/contest/2082/problem/B
*/

#include <iostream>
//#include <bits/stdc++.h>
typedef long long ll;

/*
greedy choice always works: (why?)
*/


using namespace std;

void solve() {
    int x, n, m;
    cin >> x >> n >> m;

    n = min(65, n);
    m = min(65, m);
    int save_n = n;
    int save_m = m;

    int ans_min = x;
    int ans_max = x;

    while (ans_min > 1 && m > 0) {
        ans_min = (ans_min + 1) / 2;
        m--;
    }
    while(ans_min > 0 && n > 0) {
        ans_min /= 2;
        n--;
    }
    m = save_m;
    n = save_n;
    while (ans_max > 0 && n > 0) {
        ans_max /= 2;
        n--;
    }
    while(ans_max > 0 && m > 0) {
        ans_max = (ans_max + 1) / 2;
        m--;
    }
    cout << ans_min << ' ' << ans_max << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
