/*
Problem link: https://codeforces.com/contest/2162/problem/G
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
connect everything to 2
2 * (1 + 3 + 4 + ... + n)
= 2 * (1 + 2 + 3 + 4 + ... + n) - 4
= 2 * n(n+1)/2 - 4
= n(n+1) - 4
= n^2 + (n-4)

need to subtract off n-4 by moving nodes
move (n - 4) from 2 to 1 (- (n - 4))

2 1 = 2
2 3 = 6
2 4 = 8
2 5 = 10

2+6+8+10=26=25 + (5 - 4)

handle n=5 and n=6 sep, diff=1,2 in those cases
n=5
2 1 = 2
2 3 = 6
2 4 = 8
2 5 = 10

diff=1
2 1 = 2
2 3 = 6
3 4 = 12
1 5 = 5
=25

n=6
2 1 = 2
2 3 = 6
2 4 = 8
2 5 = 10
2 6 = 12

diff=2
2 1 = 2
2 3 = 6
2 4 = 8
3 5 = 15
3 6 = 18
=49

*/

void solve() {
    int n; cin >> n;
    if (n > 6) {
        int diff = n - 4;
        for (int i = 1; i <= n; i++) {
            if (i != 2 && i != diff) {
                cout << 2 << " " << i << endl;
            }
        }
        cout << 1 << " " << diff << endl;
    } else if (n == 6) {
        cout << 2 << " " << 1 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 2 << " " << 4 << endl;
        cout << 3 << " " << 5 << endl;
        cout << 3 << " " << 6 << endl;
    } else if (n == 5) {
        cout << 2 << " " << 1 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 3 << " " << 4 << endl;
        cout << 1 << " " << 5 << endl;
    } else if (n == 4) {
        cout << 2 << " " << 1 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 2 << " " << 4 << endl;
    } else if (n == 3) {
        cout << 1 << " " << 3 << endl;
        cout << 2 << " " << 3 << endl;
    } else if (n == 2) {
        cout << -1 << endl;
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
