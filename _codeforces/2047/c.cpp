/*
Problem link: https://codeforces.com/contest/2047/problem/C
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
    vi aa(n);
    vi bb(n);
    vector<pii> a;
    vector<pii> b;
    for(int i = 0; i < n; i++) cin >> aa[i];
    for(int i = 0; i < n; i++) cin >> bb[i];
    for(int i = 0; i < n; i++) {
        int x = aa[i]; int y = bb[i];
        if (x > y) a.push_back({x, y});
        else b.push_back({x, y});
    }
    int c = -INT_MAX;
    int d = -INT_MAX;
    int ans = 0;
    for(int i = 0; i < sz(a); i++) {
        ans += a[i].first;
        c = max(a[i].second, c);
    }
    for(int i = 0; i < sz(b); i++) {
        ans += b[i].second;
        d = max(b[i].first, d);
    }
    ans += max(c, d);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
