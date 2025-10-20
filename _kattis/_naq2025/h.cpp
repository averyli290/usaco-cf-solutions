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


void solve() {
    int n; cin >> n;
    vector<double> p(n);
    vector<double> w(n);
    double total = 0.0;
    ll total_ll = 0LL;
    for(int i = 0; i < n; i++) {
        ll x, y;
        p[i] = (double) x;
        w[i] = (double) y;
        total += p * w;
        total_ll += x * y;
    }
    if (total_ll == 0LL) {
        cout << 0 << endl;
        return;
    }

    


    priority_queue<double, int> pq;
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
