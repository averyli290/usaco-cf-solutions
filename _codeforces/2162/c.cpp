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
0 0 -> 0
1 0 -> 1
0 1 -> 1
1 1 -> 0


100001
111110
*/

void solve() {
    int a, b;
    cin >> a >> b;
    vi ans;
    int m = 31;
    while (((a >> m) & 0b1) == 0b0) m--;
    int m2 = 31;
    while (((b >> m2) & 0b1) == 0b0) m2--;
    if (m2 > m) {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < m; i++) {
        if (((a >> i) & 0b1) == 0b0) {
            ans.push_back(1 << i);
        }
    }
    for(int i = 0; i <= m; i++) {
        if (((b >> i) & 0b1) == 0b0) {
            ans.push_back(1 << i);
        }
    }
    cout << sz(ans) << endl;
    if (sz(ans) == 0) return;
    for(int v : ans) {
        cout << v << " ";
    }
    cout << endl;
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
