/*
Problem link: https://codeforces.com/contest/2231/problem/F
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

3
2 1
1 2
3 3
1 2
1 3
2 3
4 3
1 2
1 3
1 4
lagrange/legendre square theorems

diff = (x+y)(x-y)
4a = (x+y)(x-y)

*/

vector<bool> prime_sieve;
vi primes;
set<int> squares;
map<int, vector<pii>> diffs;

bool f(int x) {
    for(int i : primes) {
        if (i > x) break;
        if (i % 4 == 3) {
            int ct = 0;
            while(x % i == 0) {
                ct++;
                x /= i;
            }
            if (ct % 2 == 1) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, q; cin >> n >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        int diff = b - a;
        // debug(diff);
        bool done = false;
        if (squares.find(diff) != squares.end()) {
            done = true;
            cout << 1 << endl;
        }
        if(!done && f(diff)) {
            done = true;
            cout << 2 << endl;
        }
        if(!done) {
            for(auto [x, y] : diffs[diff]) {
                if (a + x * x <= n || a - y * y >= 1) {
                    done = true;
                    cout << 2 << endl;
                }
                if (done) break;
            }
        }

        int cur = 1;
        while (diff % cur == 0 && !done) {
            if ((diff / cur) % 8 != 7) {
                cout << 3 << endl;
                done = true;
            }
            cur <<= 2;
        }
        if (!done) {
            cout << 4 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i * i <= 2e5; i++) {
        squares.insert(i * i);
    }

    prime_sieve.assign(2e5 + 1, true);
    prime_sieve[0] = false;
    prime_sieve[1] = false;
    for(int i = 2; i * i <= 2e5; i++) {
        for(int j = i + i; j <= 2e5; j += i) {
            prime_sieve[j] = false;
        }
    }
    for(int i = 0; i <= 2e5; i++) {
        if (prime_sieve[i]) {
            primes.push_back(i);
        }
    }

    for(int i = 0; i * i <= 2e5; i++) {
        for(int j = i + 1; j * j <= 2e5; j++) {
            diffs[j * j - i * i].push_back({j, i});
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }



}
