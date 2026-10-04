/*
Problem link: https://codeforces.com/contest/2267/problem/C
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
gcd must be greater than 1, optimal to pick a prime
*/

vi primes;
const int N = 3e5 + 10;
vector<bool> sieve;

void solve() {
    int n, x; cin >> n >> x;

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0ll;
    for(int p : primes) {
        ll curans = 0ll;
        if (x % p == 0) {
            for(int i = 0 ; i < n; i++) {
                if (a[i] % p == 0) {
                    curans += (ll) a[i];
                }
            }
        }
        ans = max(ans, curans);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    sieve.assign(N, true);
    primes.clear();
    sieve[0] = false;
    sieve[1] = false;
    sieve[2] = true;
    for(int i = 2; i < N; i++) {
        if (sieve[i]) primes.push_back(i);
        for(int j = i + i; j < N; j+=i) {
            sieve[j] = false;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
