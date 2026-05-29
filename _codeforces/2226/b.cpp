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
gcd(x,x+1,x+2) = 1

gcd(4, 2)

*/

void solve() {
    int n; cin >> n;
    vi p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ct = 0;
    for(int i = 1; i < n; i++) {
        if (abs(p[i] - p[i - 1]) == gcd(p[i], p[i - 1])) ct++;
    }
    cout << ct << endl;
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
