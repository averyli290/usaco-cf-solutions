/*
Problem link: https://codeforces.com/contest/2123/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int mex = 0;
    vi ans(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if (a[i - 1] == mex) mex++;
        ans[i] = mex;
    }

    cout << "  ";
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < n + 1; i++) {
        cout << ans[i] <<" ";
    }
    cout << endl;
    for(int i = 0; i < n + 1; i++) {
        // remove everything from end and everything from start
        cout << ans[n - i] - ans[i] + 1 <<" ";
    }
    cout << endl;
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