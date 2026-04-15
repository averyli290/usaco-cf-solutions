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
keep track of min values.
try to use only one index to attain values
*/

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vi p(n);
    int min_a = 0;
    int min_b = 0;
    bool a_inc = false;
    bool b_inc = false;
    int plus_a = 0;
    int plus_b = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        if (s[i] == '0') {
            a_inc = true;
            if (p[i] % 2 == 0) {
                min_a += p[i] / 2 + 1;
                plus_b += p[i] / 2;
            } else {
                min_a += (p[i] + 1) / 2;
                plus_b += (p[i] + 1) / 2 - 1;
            }
        } else {
            b_inc = true;
            if (p[i] % 2 == 0) {
                min_b += p[i] / 2 + 1;
                plus_a += p[i] / 2;
            } else {
                min_b += (p[i] + 1) / 2;
                plus_a += (p[i] + 1) / 2 - 1;
            }
        }
    }
    // cout << min_a << " " << min_b << endl;
    if (min_a > x || min_b > y) {
        cout << "NO" << endl;
        return;
    }

    // check where increase for min_a
    if (x > min_a + plus_a && !a_inc) {
        if (y - min_b < x - (min_a + plus_a)) {
            cout << "NO" << endl;
            return;
        }
    }
    if (y > min_b + plus_b && !b_inc) {
        if (x - min_a < y - (min_b + plus_b)) {
            cout << "NO" << endl;
            return;
        }
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
