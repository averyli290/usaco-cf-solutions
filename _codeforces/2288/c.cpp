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



ll f1(int numdigs, vector<bool> digits, ll a, vi av) {
    // return largest number smaller than a
    ll ret = 0LL;
    ll cur = 1LL;
    ll temp = numdigs;
    temp--;
    while (temp> 0) {
        cur *= 10;
        temp--;
    }
    // while can, match it. if no match, check if any digit below
    // if smaller exists, take that and max for rest
    // otherwise, first check if any to left have smaller digit
    // if none, return max of all with one less digit
    for(int i = 0; i < numdigs; i++) {
        if (digits[av[i]]) {
            ret += cur * av[i];
            cur /= 10;
        } else {
            while (i > 0) {
                for(int d = av[i] - 1; d >= 0; d--) {
                    if (digits[d]) {
                        ret += cur * d;
                        cur /= 10;
                        i++;
                        int maxdig = 9;
                        while (!digits[maxdig]) maxdig--;
                        while (i < numdigs) {
                            ret += cur * maxdig;
                            cur /= 10;
                            i++;
                        }
                        return ret;
                    }
                }
                ret -= cur * av[i - 1];
                cur *= 10;
                i--;
            }
            for(int d = av[i] - 1; d >= 0; d--) {
                if (digits[d]) {
                    ret += cur * d;
                    cur /= 10;
                    i++;
                    int maxdig = 9;
                    while (!digits[maxdig]) maxdig--;
                    while (i < numdigs) {
                        ret += cur * maxdig;
                        cur /= 10;
                        i++;
                    }
                    return ret;
                }
            }
            ret = 0LL;
            int maxdig = 9;
            while (!digits[maxdig]) maxdig--;
            for(int j = 0; j < numdigs - 1; j++) {
                ret *= 10;
                ret += maxdig;
            }
            return ret;
        }
    }
    return ret;
}

ll f2(int numdigs, vector<bool> digits, ll a, vi av) {
    // return smallest number larger than a
    ll ret = 0LL;
    ll cur = 1LL;
    ll temp = numdigs;
    temp--;
    while (temp> 0) {
        cur *= 10;
        temp--;
    }
    // while can, match it. if no match, check if any digit above
    // if large exists, take that and min for rest
    // otherwise, return min of all with one less digit
    for(int i = 0; i < numdigs; i++) {
        if (digits[av[i]]) {
            ret += cur * av[i];
            cur /= 10;
        } else {
            while (i > 0) {
                for(int d = av[i] + 1; d <= 9; d++) {
                    if (digits[d]) {
                        ret += cur * d;
                        cur /= 10;
                        i++;
                        int mindig = 0;
                        while (!digits[mindig]) mindig++;
                        while (i < numdigs) {
                            ret += cur * mindig;
                            cur /= 10;
                            i++;
                        }
                        return ret;
                    }
                }
                ret -= cur * av[i - 1];
                cur *= 10;
                i--;
            }
            for(int d = av[i] + 1; d <= 9; d++) {
                if (digits[d]) {
                    ret += cur * d;
                    cur /= 10;
                    i++;
                    int mindig = 0;
                    while (!digits[mindig]) mindig++;
                    while (i < numdigs) {
                        ret += cur * mindig;
                        cur /= 10;
                        i++;
                    }
                    return ret;
                }
            }
            ret = 0LL;
            int mindig = 0;
            while (!digits[mindig]) mindig++;
            for(int j = 0; j < numdigs + 1; j++) {
                ret += mindig;
                ret *= 10;
            }
            return ret;
        }
    }
    return ret;
}

void solve() {
    ll a; cin >> a;
    int n; cin >> n;
    vector<bool> d(10, false);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        d[x] = true;
    }
    if (a == 0LL) {
        for(int i = 0; i < 10; i++) {
            if (d[i]) {
                cout << i << endl;
                return;
            }
        }
    }

    vi av;
    ll temp = a;
    int pow = 0;
    while(temp > 0) {
        pow++;
        av.push_back(temp % 10);
        temp /= 10;
    }
    reverse(all(av));

    // debug(f1(pow, d, a, av));
    // debug(f1(pow + 1, d, a, av));
    // debug(f2(pow, d, a, av));
    // debug(f2(pow - 1, d, a, av));
    vll vals;
    ll v1 = f1(pow, d, a, av);
    ll v2 = f2(pow, d, a, av);
    if (v2 == 0 && !d[0]) v2 = v1;
    cout << min(abs(a - v1), abs(a - v2)) << endl;

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