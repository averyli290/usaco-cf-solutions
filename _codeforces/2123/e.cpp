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
    map<int, int> freq;
    sort(all(a));
    int mex = 0;
    vi ans(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        freq[a[i - 1]]++;
        if (a[i - 1] == mex) mex++;
        ans[i] = mex;
    }

    // for a given value i, we can make the mex i if k <= n - i elements left over
    // and can remove all elements which are i
    vi d(n + 2, 0); // difference array

    for (int i = 0; i <= mex; i++) {
        // want to get mex = i
        int most_remove = n - i;
        int least_remove = freq[i];
        if (most_remove >= least_remove) {
            d[most_remove + 1]--;
            d[least_remove]++;
        }
    }

    int cur = 0;
    for(int i = 0; i <= n; i++) {
        cur += d[i];
        cout << cur << " ";
    }
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