/*
Problem link: https://codeforces.com/contest/2123/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long long INF = 1e18;


void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int numOnes = 0;
    
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            numOnes += 1;
        }
    }
    if (k >= numOnes) {
        cout << "alice" << endl;
        return;
    }
    if (n >= 2 * k) {
        cout << "bob" << endl;
        return;
    }
    if (numOnes - 1 - k > k) {  // middle is always a 1 now, alice wants to merge it if possible. not possible if there are at least k other 1s when n < 2k
        cout << "bob" << endl;
        return;
    }
    cout << "alice" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
