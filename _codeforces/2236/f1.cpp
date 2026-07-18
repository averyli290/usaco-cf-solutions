/*
Problem link: https://codeforces.com/contest/2236/problem/F1
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
const ll M = 1e9+7;


// map<int, ll> f(int x) {
void f(int x, map<int, ll>& mp) {
    for(int i = 2; i * i <= x; i++) { // only have to check prime factors up to sqrt(x)
        while (x % i == 0) {
            x /= i;
            mp[i]++;
        }
    }
    if(x > 1) mp[x]++; // remember to add x itself as a prime factor here...
}

void solve() {
    int n, x; cin >> n >> x;

    vi a(n);
    map<int, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        f(a[i], mp);
    }

    ll ans = 1ll;

    for(auto [k, v] : mp) {
        ans *= v + 1;
        ans %= M;
    }

    cout << ans << endl;

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
