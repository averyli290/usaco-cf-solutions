/*
Problem link: https://codeforces.com/contest/2065/problem/G
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
const long long INF = 1e18;

const int MAX_N = 1E5 + 1;

/*
a <= b
if a and b are distinct primes good
if b % a == 0 and b is semi prime good (a is either semi prime or a prime divisor)

freq array maintained throughout iteration

*/

bool isprime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    map<int, ll> freq;

    ll ans = 0;
    ll total_primes = 0;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        // update freq
        freq[cur]++; 
        total_primes += (ll) isprime(cur); // update total_primes

        if (isprime(cur)) { // distinct primes
            ans += total_primes - freq[cur];
        } else {
            int div = 2;
            while (cur % div != 0 && div * div <= cur) {
                div++;
            }
            if (isprime(div) && isprime(cur / div)) {// b is semiprime
                ans += freq[div] + freq[cur];
                if (cur / div != div) {     // avoid overcounting is cur / div == div
                    ans += freq[cur / div];
                }
            }
        }

        //cout << i + 1 << " " << ans << endl;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
