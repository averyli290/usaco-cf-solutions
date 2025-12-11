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

void solve() {
    int n; cin >> n;
    vi b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(all(b));
    reverse(all(b));
    int rem = n - 1;
    int idx = 0;
    while (rem > 0 && idx < n) {
        if (rem <= b[idx] - 1) {
            rem = 0;
            b[idx] -= rem;
        } else {
            rem -= b[idx] - 1;
            b[idx] = 1;
        }
        idx++;
    }
    // debug(idx);
    // debug(rem);
    b.push_back(0);
    if (rem > 0) {
        for (int i = 0; i < n + 1; i++) {
            if (b[i] == 0) {
                cout << i - rem << endl;
                return;
            }
        }
    } else {
        for (int i = 0; i < n + 1; i++) {
            if (b[i] == 0) {
                cout << i << endl;
                return;
            }
        }
    }
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
