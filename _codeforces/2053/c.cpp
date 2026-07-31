/*
Problem link: https://codeforces.com/contest/2053/problem/C
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
mirror to other side to get n + 1
all segs are same len at each iter
num segs / 2 total amount of n + 1 values
*/

void solve() {
    ll n, k; cin >> n >> k;
    ll sum = n + 1;
    ll cursegs = 1ll;
    ll totsegs = 0ll;
    while(n >= k) {
        if (n % 2 == 1) {
            totsegs += cursegs;
        }
        n /= 2;
        cursegs *= 2;
    }
    cout << sum * totsegs / 2 << endl;
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
