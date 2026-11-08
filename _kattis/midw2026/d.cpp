/*
Problem link:
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

a0 + a2 = a3
a1 + a3 = a4
a0 + a1 + a2 = a4
a2 + a4 = a5
a0 + a1 + 2a2 = a5


*/

void solve() {
    int a3, a4, a5; cin >> a3 >> a4 >> a5;
    int a0, a1, a2;
    a2 = a5 - a4;
    a0 = a3 - a2;
    a1 = a4 - a2 - a0;
    cout<< a0 <<" " << a1 << " " << a2 << endl;
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

