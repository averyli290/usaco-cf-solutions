/*
Problem link: https://codeforces.com/contest/2167/problems/E
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
    int n,k,x; cin >> n >> k >> x;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(all(a));
    vector<pll> diffs(n - 1);
    for(int i=0;i<n-1;i++) {
        diffs.emplace_back((a[i + 1] - a[i]) / 2, i);
    }
    diffs.emplace_back(a[0], n);
    diffs.emplace_back(x-a[n-1], n+1);
    sort(all(diffs));
    vll pref(sz(diffs) + 1, 0LL);
    for (int i = 0; i < sz(diffs); i++) {
        pref[i + 1] = pref[i];
        if (i < n) pref[i + 1] += a[i + 1] - a[i];
        else if (i == n) pref[i + 1] += a[0];
        else if (i == n + 1) pref[i + 1] += x-a[n-1];
    }

    for (int i = 0; i < sz(pref); i++) {
        if (pref[i] < )
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
