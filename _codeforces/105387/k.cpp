/*
Problem link: https://codeforces.com/gym/105387/problem/K
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

struct frac {
    int num;
    int den;
};

bool cmp(frac x, frac y) {
    return x.num * y.den < x.den * y.num;
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    
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
