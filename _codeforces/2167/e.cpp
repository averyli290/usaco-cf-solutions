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
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(all(a));

    function<pair<bool, vector<int>>(int)> check = [&] (int dist) {
        return pair<bool, vector<int>>{false, vi{}};
    };

    int lo = 0;
    int hi = x;
    vi ret;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        auto [good, ans] = check(mid);
        if(good) {
            ret = ans;
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    for(int v : ret) {
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
