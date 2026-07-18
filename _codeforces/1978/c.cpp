/*
Problem link: https://codeforces.com/contest/1978/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*

1,3
3,1

2,4
4,2

1,2
2,1

1,2,3,4,5
5,4,3,2,1

1,2,3,4
4,3,2,1

*/

void solve() {
    ll n, k; cin >> n >> k;
    ll mval = 0ll;
    for(ll i = 1ll; i <= n / 2; i++) {
        mval += (n - (i - 1) - i) * 2;
    }

    if (k < 0 || k > mval || k % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    // debug(mval);
    ll left = 1ll;
    ll right = n;
    vi ans(n + 1, 0);
    for(int i = 1; i <= n; i++) ans[i] = i;
    while(left < right) {
        ll cur = (right - left) * 2;
        if (cur <= k) {
            k -= cur;
            ans[right] = left;
            ans[left] = right;
            right--;
            left++;
        } else {
            ans[right] = right;
            right--;
        }
    }
    assert(k == 0);
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
