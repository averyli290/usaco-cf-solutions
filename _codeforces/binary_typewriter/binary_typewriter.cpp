/*
Avery Li
XX/XX/XXXX
Problem link:
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int total = n;
    int prev = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] - '0' != prev) {
            cout << "diff" << 
            prev = (prev + 1) % 2;
            total++;
        }
        total++;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
