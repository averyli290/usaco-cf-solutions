/*
Problem link: https://codeforces.com/contest/2182/problem/C
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
    vi a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    // can just fix a at index 1, figure out how many can map to for b
    vi bstarts;
    vi cstarts;
    for(int start = 0; start < n; start++) {
        bool good = true;
        for(int i = 0; i < n; i++) {
            if (a[i] >= b[(start + i) % n]) {
                good = false;
                break;
            }
        }
        if (good) bstarts.push_back(start);
    }
    // debug_vector(bstarts, sz(bstarts));
    for(int start = 0; start < n; start++) {
        bool good = true;
        for(int i = 0; i < n; i++) {
            if (b[i] >= c[(start + i) % n]) {
                good = false;
                break;
            }
        }
        if (good) cstarts.push_back(start);
    }
    cout << ((ll) sz(cstarts)) * ((ll) sz(bstarts)) * ((ll) n) << endl;
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
