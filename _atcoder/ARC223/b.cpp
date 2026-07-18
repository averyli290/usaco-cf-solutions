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
a,b,c,d
a+b % k == 0 
b+c % k == 0 
a+c % k == 0 
c+d % k == 0
b+d % k == 0

a-c % k == 0
(a-c) + (c+d) % k == 0 => a+d % k == 0

a,b,c,d
a,c,b,d

a,b,c
b,a,c
b,c,a

b,a,c
a,c,b
c,a,b

*/

void solve() {
    ll n, k; cin >> n >> k;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int curstreak = 0;
    for(int i = 0; i < n; i++) {
        if ((a[i] + a[i + 1]) % k == 0) {

        }
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
