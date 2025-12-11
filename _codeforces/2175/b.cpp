/*
Problem link:
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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
store total current xor in prev

check tot ^ cur not in prev
this effectively checks if C(prev) ^ cur = 0 where C(prev) is a tot ^ prev for some prev,
giving a suffix prev instead of prefix prev

*/

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vi ans(n);
    l--; r--;
    set<int> prev;
    int cur = 10;
    int tot = 0;
    prev.insert(0);
    for(int i = 0; i < l; i++) {
        while(prev.count(tot ^ (cur << 2)) > 0) cur++;
        ans[i] = cur << 2;
        tot ^= ans[i];
        prev.insert(tot);
    }

    ans[l] = 1;
    tot ^= ans[l];
    prev.insert(tot);
    int temp = 3;

    for(int i = l + 1; i < r - 1; i++) {
        while(prev.count(tot ^ (cur << 2)) > 0) cur++;
        ans[i] = cur << 2;
        tot ^= ans[i];
        prev.insert(tot);
        temp ^= ans[i];
    }
    if (l < r - 1) {
        ans[r - 1] = temp;
        tot ^= ans[r - 1];
        prev.insert(tot);
        ans[r] = 2;
    } else {
        ans[r] = 1;
    }
    tot ^= ans[r];
    prev.insert(tot);

    for(int i = r + 1; i < n; i++) {
        while(prev.count(tot ^ (cur << 2)) > 0) cur++;
        ans[i] = cur << 2;
        tot ^= ans[i];
        prev.insert(tot);
    }

    for(auto v : ans) {
        cout << v << " ";
    }
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
