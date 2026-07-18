/*
Problem link: https://codeforces.com/contest/2237/problem/C
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
1 4 3 2 5

1 3 7 2 5
1 3 2 9 14
*/

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n -1 ; i++) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            a[i + 1] += a[i];
        }
    }
    cout << a[n - 1] << endl;
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
