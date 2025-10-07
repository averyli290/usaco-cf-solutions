/*
Problem link: https://codeforces.com/contest/2145/problem/C
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
can check prefix and suffix counts
iterate over left pointer
binary search for where right pointer needs to be for getting same count

guarantee values ot the left
diff, need to search for the diff on the right
store diffs on the right in a map of sets, binary search for current index
*/


void solve() {
    int n; cin >> n;
    string s; cin >> s;
 
    map<int, set<int>> m;
    int cur = 0;
    vi diff(n + 1, 0);
 
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        int cur = s[i - 1] == 'a' ? 1 : -1;
        tot += cur;
        diff[i] = diff[i - 1] + cur;
    }

    if (tot == 0) {
        cout << 0 << endl;
        return;
    }

    int ans = 1000000;
    map<int, int> idx;
    for(int i = 0; i < n; i++) {
        if (idx.count(diff[i] - tot)) {
            ans = min(ans, i - idx[diff[i] - tot]);
        }
        idx[diff[i]] = i;
    }

    if (ans == 1000000) {
        cout << -1 << endl;
    } else {
        cout << ans <<endl;
    }


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
