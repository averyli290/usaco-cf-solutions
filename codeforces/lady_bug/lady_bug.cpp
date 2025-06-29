/*
Avery Li
3/29/2025
Problem link: https://codeforces.com/contest/2092/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int a_odd = 0;
    int a_even = 0;
    int b_odd = 0;
    int b_even = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i % 2 == 0) {
                a_even++;
            } else {
                a_odd++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if (b[i] == '0') {
            if (i % 2 == 0) {
                b_even++;
            } else {
                b_odd++;
            }
        }
    }
    //cout << a_even << " " << a_odd << " " << b_even << " " << b_odd << endl;
    if (a_even > b_odd || a_odd > b_even) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
