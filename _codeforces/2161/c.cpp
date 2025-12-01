/*
Problem link:
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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
sort rem from greatest to least
*/

void solve() {
    ll n, x; cin >> n >> x;
    vll a(n);
    ll sub = 0LL;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if (a[i] / x > 1) {
            sub += a[i] / x - 1;
        }
    }
    sort(all(a));
    ll total = accumulate(all(a), 0LL);
    reverse(all(a));
    ll tot = 0LL;
    vll b;
    for(int i=0;i<total / x - sub; i++) {
        tot += a[i];
        b.push_back(a[i]);
    }
    vll c;
    for(int i = total / x - sub; i < n; i++) {
        c.push_back(a[i]);
    }
    ll cur = 0LL;
    ll ctr = 0LL;
    int idxb = 0;
    int idxc = 0;
    vll ans(n);
    while (ctr < n) {
        if (idxb == sz(b)) {
            ans[ctr] = c[idxc];
            cur += c[idxc];
            idxc++;
        } else if (idxc == sz(c)) {
            ans[ctr] = b[idxb];
            cur += b[idxb];
            idxb++;
        } else {
            if (((cur + b[idxb]) / x) - (cur / x) >= 1) {
                ans[ctr] = b[idxb];
                cur += b[idxb];
                idxb++;
            } else {
                ans[ctr] = c[idxc];
                cur += c[idxc];
                idxc++;
            }
        }
        // debug(idxb);
        // debug(idxc);
        ctr++;
    }
    ll totalcheck = 0LL;
    cur = 0LL;
    for(int i = 0; i < n; i++) {
        if ((cur + ans[i]) / x - (cur / x) >= 1) {
            totalcheck += ans[i];
        }
        cur += ans[i];
    }
    cout << tot << endl;
    for(ll v : ans) {
        cout << v << " ";
    }
    cout << endl;
    debug(totalcheck);
    assert(totalcheck == tot);
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
