/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/645502/problem/J
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
    vi a(n);
    for(int i=0; i<n;i++) {
        cin >> a[i];
    }
    vi ans;
    ans.push_back(a[0]);
    int ctr = 0;
    for(int i = 1; i<n;i++) {
        if (gcd(ans[ctr], a[i]) != 1) {
            ans.push_back(1);
            ctr++;
        }
        ans.push_back(a[i]);
        ctr++;
    }
    cout << sz(ans) - n << endl;
    for(int v : ans) {
        cout << v << " ";
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
