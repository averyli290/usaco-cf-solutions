/*
Avery Li
2/26/2025
Problem link: https://codeforces.com/contest/2049/problem/A
*/

/*
remove all 0's at the start and end first.
If the array contains no 0's then take subarray to be whole array.
If the array contains all 0's, then done wihtout any operation.
Otherwise, take MEX of whole array twice, second time being on just one elt.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;
void solve() {
    int n; cin >> n;
    a.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b = vector<int>();
    int i = 0;
    while (i < n && a[i] == 0) {
        i++;
    }
    int j = n - 1;
    while (j >=0 && a[j] == 0) {
        j--;
    }
    for(int k = i; k <= j; k++) {
        b.push_back(a[k]);
    }

    int zeroes = count(b.begin(), b.end(), 0);


    if (b.size() == 0) {
        cout << 0;
    } else if (zeroes == 0) {
        cout << 1;
    } else {
        cout << 2;
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
