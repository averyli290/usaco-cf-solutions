/*
Problem link: https://codeforces.com/contest/2178/problem/B
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
uusuuu
sususs

*/

void solve() {
    string r; cin >> r;
    int n = sz(r);
    int ans = 0;
    int prev = 0;
    if (r[0] == 'u') {
        ans++;
    }
    for(int i = 0; i < n-1; i++) {
        if(r[i] == 's') prev = i;
        else if(i == prev + 2) {
            prev = i;
            ans++;
        }
    }
    if (r[n - 1] == 'u') ans++;
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