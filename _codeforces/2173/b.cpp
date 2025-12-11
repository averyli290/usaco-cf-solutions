/*
Problem link: https://codeforces.com/contest/2173/problem/B
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
    vll a(n), b(n);
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n ; i++) {
        cin >> b[i];
    }
    ll neg = 0LL;
    ll pos = 0LL;
    for(int i = 0; i < n; i++) {
        ll pneg = neg;
        ll ppos = pos;
        neg = min(ppos - a[i], min(pneg - a[i], min(b[i] - ppos, b[i] - pneg)));
        pos = max(ppos - a[i], max(pneg - a[i], max(b[i] - ppos, b[i] - pneg)));
    }
    cout << max(neg, pos) << endl;
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
