/*
Problem link: https://codeforces.com/contest/2167/problems/D
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

bool is_prime(ll n) {
    for(ll i = 2LL; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    ll ans = 1LL;
    while (true) {
        ans++;
        if (!is_prime(ans)) continue;
        for(ll v : a) {
            if(v % ans != 0) {
                cout << ans << endl;
                return;
            }
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
