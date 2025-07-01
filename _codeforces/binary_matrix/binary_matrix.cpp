/*
Avery Li
3/15/2025
Problem link: https://codeforces.com/contest/2082/problem/A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>

//#include <bits/stdc++.h>
typedef long long ll;

/*
find which column need to have bit changed
find which rows need to have bit changed
match them up when possible
=> answer = max(# of bits need to change in cols, # of bits to change in rows)
*/


using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> row_xors = vector<int>(n, 0); // stores xor of row i
    vector<int> col_xors = vector<int>(m, 0); // stores xor of col j
    // vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(m, 0));
    string s;
    for (int i=0;i<n;i++) {
        cin >> s;
        for (int j=0;j<m;j++){
            int e = s[j] - '0';
            row_xors[i] = (row_xors[i] + e) % 2;
            col_xors[j] = (col_xors[j] + e) % 2;
        }
    }

    int r_sum = 0;
    int c_sum = 0;

    for(int i = 0; i < n; i++) r_sum += row_xors[i];
    
    for(int j = 0; j < m; j++) c_sum += col_xors[j];

    cout << max(r_sum, c_sum) << endl;

    //cout << max(accumulate(row_xors.begin(), row_xors.end(), 0), accumulate(col_xors.begin(), col_xors.end(), 0)) << endl;
    // why didn't this work?? idk 
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
