/*
Problem link: https://codeforces.com/contest/2284/problem/C2
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
    int a, b; cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (gcd(b - a, a) == 1) {
        cout << 1 << endl;
        cout << b - a << endl;
        return;
    }

    int nxt = a + 1;
    while (nxt < b) {
        if (gcd(nxt - a, a) == 1 && gcd(b - nxt, nxt) == 1) {
            cout << 2 << endl;
            cout << nxt - a << " " << b - nxt << endl;
            return;
        }
        nxt++;
    }
    nxt = a + 1;
    while (nxt < b - 1) {
        if (gcd(nxt - a, a) == 1 && gcd(b - 1 - nxt, nxt) == 1) {
            cout << 3 << endl;
            cout << nxt - a << " " << b - 1 - nxt << " " << 1 << endl;
            return;
        }
        nxt++;
    }
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
