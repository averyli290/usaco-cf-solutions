/*
Problem link: https://codeforces.com/contest/2154/problem/A
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
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    int x = -1;
    vi a(n);
    for(int i = 0; i < n; i++) {
        if (s[i] == '0') a[i] =0;
        else a[i] =1;
    }

    int cursum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == 1 && cursum == 0) {
            ans++;
        }
        cursum += a[i];
        if (i >= k - 1) cursum -= a[i - (k - 1)];
    }
    cout << ans << endl;

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
