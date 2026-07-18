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
even works...
exclude largest prime factor? jk nvm u gotta consider all
*/


void solve() {
    ll n; cin >> n;
    vll ans;
    ans.push_back(1);
    vll other;
    vll fs;
    ll m = n;
    for(ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            fs.push_back(i);
            while(m % i == 0) m /= i;
        }
    }
    if (m > 1) fs.push_back(m);

    for(ll i = 2; i < n - 1; i++) {
        if ((i * i) % n == 1) {
            other.push_back(i);
        } else {
            bool good = true;
            for(ll f : fs) if (i % f == 0) good =false;
            if (good) ans.push_back(i);
        }
    }
    // recombine groups of 4 if possible
    // make -1^2=1
    // remember n-1=-1 mod n
    ll last = 0;
    for(ll i = 3; i < sz(other); i += 4) {
        ans.push_back(other[i - 3]);
        ans.push_back(other[i - 2]);
        ans.push_back(other[i - 1]);
        ans.push_back(other[i]);
        last = i + 1;
    }
    if (sz(other) - last >= 2) {
        ans.push_back(other[last]);
        ans.push_back(other[last + 1]);
        ans.push_back(n - 1);
    }
    sort(all(ans));
    cout << sz(ans) << endl;
    // int temp = 1;
    for(int i : ans)  {
        // temp *= i;
        // temp %= n;
        cout << i << " ";
    }
    // debug(temp);
    // assert(temp == 1);
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
