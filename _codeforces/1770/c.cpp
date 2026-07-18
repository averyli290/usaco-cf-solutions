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
2 even, 2 odd bad

if for a prime p there exists a value mod p with freq < 2,
can add a number x s.t. no two numbers are divisible at same time by this p

do this for all p

*/


void solve() {
    int n;
    ll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int evenct = 0;
    int oddct = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) evenct++;
        else oddct++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
