/*
Problem link: https://codeforces.com/contest/2123/problem/A
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
0 1 2 3 4 5
*/

void solve() {
    int n; cin >> n;
    if (n <= 3) {
        cout << "ALICE" << endl;
        return;
    } 
    if (n % 4 == 0) {
        cout << "BOB" << endl;
        return;
    }
    cout << "ALICE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
