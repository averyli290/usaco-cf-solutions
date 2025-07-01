/*
Problem link: https://codeforces.com/contest/2010/problem/C2
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

/*
p = 1eE9+9
hash = (hash * base) + char (mod p)

cur_hash -= char

 bcd
abcd

rolling hash
compute hash of substring by calculating all prefix hashes
subtract off prefix to get substring, divide by p^(len(prefix)) (use mod inverse)

*/

const ll m = 1E9 + 9;

ll inv(ll a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

void solve() {
    string s; cin >> s;
    int n = sz(s);

    vector<ll> hash(n, 0);
    const int p = 31;
    ll hash_value = 0;
    ll p_pow = 1;
    vector<ll> p_inv(n + 1);
    p_inv[0] = 1;
    for (int i = 0 ; i < n ;i++) {
        char c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        hash[i] = hash_value;
        p_pow = (p_pow * p) % m;
        p_inv[i + 1] = inv(p_pow);
    }

    for(int x = 1; x < (n + 1) / 2; x++) {
        ll left = hash[n - x - 1];
        ll right = (hash[n - 1] - hash[x - 1] + m) * p_inv[x] % m;
        if (left == right) {        // extra check on hash collision
            bool good = true;
            for (int i = 0; i < n - x; i++) {
                if (s[i] != s[i + x]) {
                    good = false;
                }
            }
            if (good) {
                cout << "YES" << endl;
                cout << s.substr(0, n - x) << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
