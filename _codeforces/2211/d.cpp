/*
Problem link: https://codeforces.com/contest/2211/problem/D
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
this dog is so cute
https://www.youtube.com/watch?v=ZvlHgbILcC8

C(#1d, 1) + 2^1*C(#2d, 1) + ...  + 2^29*C(#30d, 1) = b[0]
C(#1d, 2) + 2^1*C(#2d, 2) + ...  + 2^29*C(#30d, 2) = b[1]
.
.
.
C(#1d, n) + 2^1*C(#2d, n) + ...  + 2^29*C(#30d, n) = b[n-1]
#xd <= n

find where C(#xd,k)=1, #xd=k. Do this by finding if given current
values, if difference with current b[i] is non-zero. then greedily find the
bits required to make the difference match
*/

vll factorial;
vll inverse_factorial;
const ll M = 1e9+7;
ll inv(ll a) {
  return a <= 1 ? a : M - (long long)(M/a) * inv(M % a) % M;
}

long long C(ll n, ll k) {
    if (k > n) return 0ll;
    return factorial[n] * inverse_factorial[k] % M * inverse_factorial[n - k] % M;
}

void solve() {
    int n; cin >> n;
    vll b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vll ct(29, 0ll);
    for(int i = n; i >= 1; i--) {
        ll curtot = 0ll;
        ll p = 1;
        for(int j = 0; j < 29; j++) curtot += C(ct[j], i) * (1ll << j) % M;
        ll rem = (b[i - 1] - curtot + 2 * M) % M;   // remaining needed at current choose level
        // debug(rem);
        // bro i have NO CLUE why you can greedy this i just assumed it would work
        for(int j = 28; j >= 0; j--) {
            if (ct[j] > 0) continue;
            ll temp = (1ll << j) % M;
            if (temp <= rem) {
                rem -= temp;
                ct[j] = i;          // C(i,i) = 1, 1*temp=temp, contribute that to rem
            }
        }
        // debug(rem);
        // assert(rem == 0ll);
    }
    // distribute bits however you want since by combinatorics 
    // all subsequences will be covered so sum will be the same
    vll a(n, 0ll);
    for(int i = 0; i < 29; i++) {
        for(int j = 0; j < ct[i]; j++) {
            a[j] += (1 << i);
        }
    }
    for(ll v : a) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll maxn = 1e5;
    factorial.assign(maxn + 1, 0ll);
    inverse_factorial.assign(maxn + 1, 0ll);
    ll cur = 1;
    for(ll i = 1; i <= maxn; i++) {
        cur = (cur * i) % M;
        factorial[i] = cur;
        inverse_factorial[i] = inv(cur);
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
