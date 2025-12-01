/*
Problem link: https://codeforces.com/contest/2005/problem/B2
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
    int n, m, q;
    cin >> n >> m >> q;
    vi b(m);
    vi a(q);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < q; i++) cin >> a[i];
    sort(all(b));

    for (int query : a) {
        int idx = lower_bound(all(b), query) - b.begin();
        int temp = 1;
        // debug(query);
        if (idx == 0) {
            temp = max(temp, b[0] - 1);
        }
        if (idx == m) {
            temp = max(temp, n - b[m - 1]);
        }
        if (idx >= 1 && idx < m){
            temp = max(temp, (b[idx] - b[idx - 1]) / 2);
        }
        cout << temp << endl;
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
