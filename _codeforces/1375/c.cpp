/*
Problem link: https://codeforces.com/contest/1375/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef vector<int> vi;


void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    int cur = a[left];
    int left = 1;
    while(left < n) {
        if (cur < a[left]) {
            
            left++;
        }
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
