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

if b_i = 0, n cannot win
if b_i = 1, 1 cannot win


going backwards how many there are in a row
if at least one 0, can make 1 win that
how recent is last 0?

same for 1.

*/


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int last0 = -1;
    int last1 = -1;
    for(int x = 2; x <= n; x++) {
        int cur = s[x - 2] - '0';
        if (cur == 0) { // want to check when the last 1 is , every 0 after that decreases it by 1
            if (last1 == -1) {
                cout << 1 << " ";
            } else {
                cout << x - (x - 1 - last1)<< " ";
            }
        } else {
            if (last0 == -1) {
                cout << 1 << " ";
            } else {
                cout << x - (x - 1 - last0) << " ";
            }
        }
        if (cur == 0) {
            last0 = x - 1;
        } else {
            last1 = x - 1;
        }
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
