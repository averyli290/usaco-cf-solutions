/*
Problem link: https://codeforces.com/contest/2124/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

/*
make palindrome of size k - 1?
remove everything except for smallest
smallest k-1 are protected
*/


void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi b = a;
    sort(all(b));
    int threshold = b[k - 1];       // remove everything below threshold,
                                    // if palindrome exists using elements larger, then
                                    // also exists not using any of those elements.
                                    // all of them can be removed
    vi c;
    for(int i = 0; i < n; i++) {
        if (a[i] <= threshold) {
            c.push_back(a[i]);
        }
    }
    // must keep at least k - 1 elts
    // can remove up to sz(c) - (k - 1) elts
    int ct = sz(c) - (k - 1);
    int left = 0;
    int right = sz(c) - 1;
    while(left < right) {
        if (c[left] == c[right]) {
            left++; right--;
        }
        else {
            // check if fixable
            if (c[left] == threshold) {
                left++;
            } else if (c[right] == threshold) {
                right--;
            } else {        // not fixable, can't remove anything except for threshold
                cout << "NO" << endl;
                return;
            }
            ct--;
        }
        if (ct < 0) {
            cout << "NO" << endl;
            return;
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
