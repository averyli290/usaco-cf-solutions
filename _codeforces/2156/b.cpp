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
7
1 1 5
1 1 3
1 1 2
*/

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    while (q--) {
        int a; cin >> a;
        int ans = 0;
        int ctr = 0;
        while (a > 0 && ctr < 20) {
            if (s[c] == 'A') a--;
            else a /= 2;
            ans++;
            ctr++;
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
