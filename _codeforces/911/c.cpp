/*
Problem link: https://codeforces.com/contest/911/problem/C
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


void solve() {
    int ct1 = 0;
    int ct2 = 0;
    int ct3 = 0;
    int ct4 = 0;
    for(int i = 0; i < 3; i++) {
        int x; cin >> x;
        if (x == 1) ct1++;
        if (x == 2) ct2++;
        if (x == 3) ct3++;
        if (x == 4) ct4++;
    }
    if (ct1 >= 1) {
        cout << "YES" << endl;
        return;
    }
    if (ct2 >= 2) {
        cout << "YES" << endl;
        return;
    }
    if (ct3 >= 3) {
        cout << "YES" << endl;
        return;
    }
    if (ct2 == 1 && ct4 == 2) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
