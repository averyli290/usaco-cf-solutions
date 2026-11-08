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
*/

vector<bool> sieve;
vi primes;

void solve() {
    int n; cin >> n;
    vi a(n);
    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cout << *lower_bound(all(primes), a[i]) << " ";

    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve.resize(2E5 + 1, true);
    primes.push_back(1);
    for(int i = 2; i <= 2E5; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= 2E5; j+=i) {
                sieve[j] = false;
            }
        }
    }
    // for(int i : primes) {
    //     cout << i << " ";
    // }
    // cout << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
