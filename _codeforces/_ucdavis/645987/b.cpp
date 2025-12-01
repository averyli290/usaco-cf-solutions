/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/645987/problem/B
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
    vector<pii> a(n);
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a[i] = pii{x, i};
    }
    sort(all(a));

    for(int i=0; i<(n + 1)/2; i++) {
        if (a[i].first + a[n - i - 1].first != a[0].first + a[n - 1].first) {
            cout << -1 << endl;
            return;
        }
    }

    vi ans(n);
    for(int i=0; i<(n + 1)/2; i++) {
        int x = a[i].second;
        int y = a[n - i - 1].second;
        ans[x] = y;
        ans[y] = x;
    }

    for(int v : ans) {
        cout << v + 1 << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
