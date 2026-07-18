
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
keep track of min values.
try to use only one index to attain values
r u trolling
*/

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vll p(n);
    int min_a = 0;
    int min_b = 0;
    bool a_inc = false;
    bool b_inc = false;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        if (s[i] == '0') {
            a_inc = true;
            min_a += p[i] / 2 + 1;
        } else {
            b_inc = true;
            min_b += p[i] / 2 + 1;
        }
    }

    // what a troll u forgot to check this
    if (accumulate(all(p), 0ll) > x + y) {
        cout << "NO" << endl;
        return;
    }
    if (min_a > x || min_b > y) {
        cout << "NO" << endl;
        return;
    }

    if (!a_inc) {
         if (x <= y - n) cout << "YES" << endl;
         else cout << "NO" << endl;
         return;
    }
    if (!b_inc) {
         if (y <= x - n) cout << "YES" << endl;
         else cout << "NO" << endl;
         return;
    }
    cout << "YES" << endl;
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
