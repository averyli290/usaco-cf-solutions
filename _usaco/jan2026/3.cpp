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
10101
10001


same remainder => lost 1 gained 1 or lost 0 gained 0
diff remainder => lost 1 gained 0 or lost 0 gained 1

assume everything is 1's

greedy place all 1's at start with leftmost 0 if needed? does that work


11011

110

111101111

every parity switch has to make the next number opposite

swapped parity indices are k-1 consecutive apart, length 
5 2
1001
1
3

01110

1010
1
2

01100
10011

101010

*/

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi a(n - k + 1);
    for(int i = 0 ; i < n - k + 1; i++) a[i] = s[i] - '0';
    int ct = 0;
    vector<bool> vis(n, false);
    int minval = 0;
    int maxval = 0;
    int totct = 0;
    for(int i = 0; i < n - k + 1; i++) {
        if (vis[i]) continue;
        if (i + k - 1 < n - k + 1 && a[i] != a[i + k - 1]) {
            int j = i;
            int ctr = 1;
            vis[i] = true;
            while(j + k-1 < n - k + 1 && a[j] != a[j + k - 1]) {
                totct++;
                ctr++;
                vis[j] = true;
                j += k - 1;
            }
            // debug(ctr);
            // if (ctr % 2 == 1) oddct++;
            minval += ctr / 2;
            maxval += (ctr+1) / 2;
        }
    }
    debug(totct);
    debug(minval);
    debug(maxval);
    cout << n - totct +minval << " " << n - totct +maxval<< endl;



    // vi ansmax(n);
    // for(int i = 1; i < k; i++) {
    //     ansmax[i] = 1;
    // }
    // if (k % 2 == 0 && a[0] % 2 == 0) ansmax[0] = 1;
    // else if (k % 2 == 0 && a[0] % 2 == 1) ansmax[0] = 0;
    // else if (k % 2 == 1 && a[0] % 2 == 0) ansmax[0] = 0;
    // else if (k % 2 == 1 && a[0] % 2 == 1) ansmax[0] = 1;
    // for (int i = 1; i < n - k + 1; i++) {
    //     if (a[i] != a[i - 1]) { // if parity change
    //         if (ansmax[i - 1] == 1) ansmax[i - 1 + k] = 0;
    //         else ansmax[i - 1 + k] = 1;
    //     } else { // if no parity change
    //         if (ansmax[i - 1] == 1) ansmax[i - 1 + k] = 1;
    //         else ansmax[i - 1 + k] = 0;
    //     }
    // }

    // vi ansmin(n, 0);
    // for(int i = 1; i < k; i++) {
    //     ansmin[i] = 0;
    // }
    // if (a[0] % 2 == 1) ansmin[0] = 1;
    // for (int i = 1; i < n - k + 1; i++) {
    //     if (a[i] != a[i - 1]) { // if parity change
    //         if (ansmin[i - 1] == 1) ansmin[i - 1 + k] = 0;
    //         else ansmin[i - 1 + k] = 1;
    //     } else { // if no parity change
    //         if (ansmin[i - 1] == 1) ansmin[i - 1 + k] = 1;
    //         else ansmin[i - 1 + k] = 0;
    //     }
    // }
    // // for(int x : ansmin) cout << x;
    // // cout << endl;
    // int x = accumulate(all(ansmin), 0);
    // int y = accumulate(all(ansmax), 0);
    // if (k == 1) {
    //     cout << x << " " << y << endl;
    //     return;
    // } 
    // array<int, 2> temp1 = {x, n - x};
    // array<int, 2> temp2 = {y, n - y};
    // // debug(x);
    // // debug(y);
    // cout << *min_element(all(temp1)) << " " << *max_element(all(temp2)) << endl;
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
