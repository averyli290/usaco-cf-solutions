/*
Problem link: https://codeforces.com/contest/2056/problem/A
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
    int n, m; cin >> n >> m;
    int bx = INT_MAX;
    int by = INT_MAX;
    int mx = 0;
    int my = 0;
    int curx = 0;
    int cury = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        curx += x;
        cury += y;
        bx = min(bx, curx);
        by = min(by, cury);
        mx = max(mx, curx + m);
        my = max(my, cury + m);
    }
    cout << 2 * (mx - bx) + 2 * (my - by) << endl;
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
