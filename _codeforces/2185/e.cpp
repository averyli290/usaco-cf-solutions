/*
Problem link: https://codeforces.com/contest/2185/problem/E
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*
keep track of max left and max right amount moved
sort spikes and robots
two pointer
*/


void solve() {
    int n, m, h; cin >> n >> m >> h;
    debug(n);
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi a2(all(a));
    vi b(m);
    vi c(m);
    // for (int v : a) cout << v << " ";
    for(int i = 0; i < m; i++) cin >> b[i] >> c[i];
    for(int i = m - 1; i >= 0; i--) {
        if (a[b[i] - 1] + c[i] > h) {
            for(int j = m - 1; j > i; j--) {
                if (b[j] - 1 != b[i] - 1) a2[b[j] - 1] += c[j];
                else break;
            }
            for (int v : a2) cout << v << " ";
            cout << endl;
            return;
        }
        a[b[i] - 1] += c[i];
    }
    for (int v : a) cout << v << " ";
    cout << endl;
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
