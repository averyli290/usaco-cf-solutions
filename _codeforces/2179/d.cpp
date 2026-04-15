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
every single time decreases the number of 1's
choose largest first
then choose smallest which decreases, then second smallest
n, 

3 0 1 2
11 -> 00 -> 00 -> 00
3 1 0 2
11 -> 10 -> 00 

7
111 -> 110 -> 100 -> 000

0 0b0
1 0b1
2 0b10
3 0b11
4 0b100
5 0b101
6 0b110
7 0b111
8 0b1000
9 0b1001
10 0b1010
11 0b1011
12 0b1100
13 0b1101
14 0b1110
15 0b1111

*/

void solve() {
    int n; cin >> n;
    set<int> used;
    int prevcur = (1 << n);
    int cur = (1 << n) - 1;
    for (int i = n - 1; i >= 0; i--) {
        // int shift = (1 << (n - 1 - i));
        int temp = 0;
        // debug(cur);
        // debug(i);
        // debug(cur +j (0b1 << (i - 1)));
        while(cur + (temp << (i + 1)) < (1 << n)) {
            if (used.count(cur + (temp << (i + 1))) == 0) {
                // cout << "cur " << cur << " ";
                cout << cur + (temp << (i + 1)) << " ";
                used.insert(cur + (temp << (i + 1)));
            }
            temp += 1;
        }
        cur -= 1 << i;
    }
    for(int i = 0; i < 1 << n; i++) {
        if (used.count(i) == 0) {
            cout << i << " ";
            // used.insert(i);
        }
    }
    // debug(sz(used));
    // assert(sz(used) == (1 << n));
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
