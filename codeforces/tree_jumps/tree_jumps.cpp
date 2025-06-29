/*
Avery Li
2/27/2025
Problem link: https://codeforces.com/contest/2070/problem/D
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#include <vector>


/*
find depth d of tree

get depth of each node

dp[i] = num of valid sequences with depth i
//dp[i][k] = num of valid sequences with depth i ending at vertex k

dp[i + 1] = dp[i] * (num of i+1 depth nodes) - 
            for each i depth node, (the number of ways to get to that node)

dp1[i] = num of valid sequences to vertex i
dp2[j] = num of valid sequences with depth j

*/


void solve() {
    int n;
    cin >> n;
    vector<int> tree = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
