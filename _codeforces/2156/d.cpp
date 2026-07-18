/*
Problem link: https://codeforces.com/contest/2156/problem/D
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
check odds/evens first
eliminate by increasing bit
log n levels of decreasing size = 2n
*/

int q(int idx, int v) {
    cout << "? " << idx << " " << v << endl; cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    vi rem;
    for(int i = 0; i < n - 1; i++) rem.push_back(i + 1);
    int cur = 1;
    int bit = 0;
    int in_a = 0;       // num count at cur level which doesnt contain current target bit
    set<int> vals;
    for(int i = 1; i <= n; i++) {
        if (i % 2 == 0) in_a++;
        vals.insert(i);
    }
    ll ans = 0ll;
    while(sz(rem) > 0) {
        vi a, b;
        // debug(in_a);
        int res;
        for(int i = 0; i < sz(rem); i++) {
            res = q(rem[i], cur);
            if (res == 0) a.push_back(rem[i]);
            else b.push_back(rem[i]);
        }
        // cout << "a: "; for(int v : a) cout << v <<  " ";
        // cout << endl;
        // cout << "b: "; for(int v : b) cout << v <<  " ";
        // cout << endl;
        set<int> newvals;
        if (sz(a) < in_a) {
            rem = a;
            for(int v : vals) {
                if (((v >> bit) & 1) == 0) newvals.insert(v);
            }
        } else {
            rem = b;
            ans += cur;
            for(int v : vals) {
                if (((v >> bit) & 1) == 1) newvals.insert(v);
            }
        }
        vals = newvals;
        in_a = 0;
        cur <<= 1;
        bit++;
        for (int v : vals) if (((v >> bit) & 1) == 0) in_a++;
    }
    cout << "! " << *vals.begin() << endl;
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
