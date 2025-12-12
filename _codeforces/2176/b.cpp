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
longest in a row log 2

10000
11000 + 1
11110 + 2
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int start = 0;
    bool is_start = true;
    int cur = 0;
    int maxval = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (is_start) {
                is_start = false;
            } else {
                maxval = max(cur, maxval);
                cur = 0;
            }
        } else {
            if (is_start) {
                start++;
            } else {
                cur++;
            }
        }
    }
    maxval = max(maxval, start + cur);
    cout << maxval << endl;
    return;
    int ans = 0;
    int val = 1;
    while (val <= maxval) {
        ans += val;
        val *= 2;
    }
    cout << ans << endl;
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
