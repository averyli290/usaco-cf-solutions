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
const long long INF = 1e18;

/*
dp
all valid sequences for n remain valid for n + 1, adding something from [1, n + 1] at to the end
on i-th op, if not 0, can always remove the i-th token, so there is always a move

dp[i][j] = # of ways to remove j elts with sequence of length i (has i - j 0's)

keep number of ways to remove last token or not remove last token
dp[i][0] = # of ways to do without removing last
dp[i][1] = # of ways to do with removing last

dp[i + 1][0] = dp[i][1]

dp[i][j] = # of ways to remove token j from i tokens

adding 1:
- can always remove n + 1 (sum of dp[n][j] for all j)
    - number of ways to remove UP TO n (inclusive), then remove n + 1
- adding n => remove all where n is removed previously
    - keep track of all where n is removed and where n is not removed
    - possibitlities are also added to for when n + 1 is removed
- adding a given a
    - all possibilities must be possible for any b in [a + 1, n + 1], and added to those

- when can remove n?
- number of ways to remove UP TO n - 1 (inclusive), then remove n, keep n + 1 (works for all appending to end except for )

adding a given a in [1, n + 1]:
how many ways are there to remove a given b in [a, n + 1]?

b is included in all a in [1, b]

*/

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
