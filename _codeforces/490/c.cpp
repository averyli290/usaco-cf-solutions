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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    ll a, b; cin >> a >> b;
    int n = sz(s);
    ll front = (s[0] - '0') % a;
    ll back = 0ll;
    for(int i = 1; i < n; i++) {
        back *= 10;
        back += s[i] - '0';
        back %= b;
    }

    if (front == 0ll && back == 0ll && s[1] != '0') {
        cout << "YES" << endl;
        cout << s.substr(0, 1) << endl;
        cout << s.substr(1, n) << endl;
        return;
    }

    for(int i = 1; i < n; i++) {
        // debug(i);
        // debug(front);
        // debug(back);
        // debug(s[i]);
        front *= 10;
        front += s[i] - '0';
        front %= a;
        back -= (s[i] - '0') * binpow(10, n - i - 1, b);
        back %= b;
        back += 2 * b;
        back %= b;
        if (i < n - 1 && front == 0ll && back == 0ll && s[i + 1] != '0') {
            cout << "YES" << endl;
            cout << s.substr(0, i + 1) << endl;
            cout << s.substr(i + 1, n) << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
