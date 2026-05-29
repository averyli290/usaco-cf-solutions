/*
Problem link: https://codeforces.com/problemset/problem/235/B
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
dp[i][0] = expected if ending on x
dp[i][1] = expected if ending on o

dp[i][0] = (1-p_i)*(dp[i - 1][0]+dp[i - 1][1])
dp[i][1] = p_i*(dp[i - 1][0] + 1) + p_i*(dp[i - 1][1])
*/

void solve() {

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
