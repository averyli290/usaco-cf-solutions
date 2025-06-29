/*
Avery Li
4/2/2025
Problem link: https://codeforces.com/contest/2092/problem/E
*/

/*
DP?

dp_e[i][j][0] = # of ways to get an even number of different adjacent cells after painting (i, j) black
dp_e[i][j][1] = ''                                                                         (i, j) white
dp_o[i][j][0] = # of ways to get an odd number of different adjacent cells after painting  (i, j) black
dp_o[i][j][1] = ''                                                                         (i, j) white

bounds suggest that dp on n*m is not feasible...

Observation: a cell with an even number of neighbors does not matter, does not change parity of differently colored adjacent cells


*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

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
