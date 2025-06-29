/*
Avery Li
4/28/2025
Problem link: https://codeforces.com/contest/2104/problem/C
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> a;
    set<int> b;

    string c; cin >> c;
    for (int i = 1; i <= n; i++) {
        if (c[i-1] == 'A') { a.insert(i); }
        else { b.insert(i); }
    }


    if (a.find(1) != a.end() && a.find(n) != a.end()) {
        cout << "ALICE" << endl;
        return;
    }
    if (b.find(1) != b.end() && b.find(n) != b.end()) {
        cout << "BOB" << endl;
        return;
    }

    int as = a.size();
    int bs = b.size();

    // handle 2 case separately 

    if (as > bs) {
        cout << "ALICE" << endl;
        return;
    }
    cout << "BOB" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
