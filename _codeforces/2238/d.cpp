/*
Problem link: https://codeforces.com/contest/2238/problem/D
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
2^3*3*5
120
60 40
15 10
5
3
2

120
60
30
15
5
3

120
40
20
10
5
2


3 + 

primes are on their own

# of primes + power of primes - 1

3 + 5 - 1

33:
2 + 2 - 1

64:
1 + 6 - 1

divide out by different primes at the level below top level to keep gcd above 1
but also they cant be factors of each other because each of them have different
primes the other doesn't

each prime needs its own level at the bottom

takes sum of powers - 1 to get to any prime factor at bottom

*/
void solve() {
    int n; cin >> n;

    
    vector<int> f; // prime factors
    vector<int> p; // power of prime factor

    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            f.push_back(d);
            p.push_back(0);
            while (n % d == 0) {
                n /= d;
                p[sz(p) - 1]++;
            }
        }
    }
    if (n > 1) {
        f.push_back(n);
        p.push_back(1);
    }

    cout << sz(f) + accumulate(all(p), 0) - 1 << endl;
    
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
