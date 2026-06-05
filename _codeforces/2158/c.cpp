/*
Problem link: https://codeforces.com/contest/2158/problem/C
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

/*
even normal
odd check if used current to maximize the score
*/

void solve() {
    int n, k; cin >> n >> k;
    vll a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (k % 2 == 0) {
        ll cur = 0ll;
        ll mval = a[0];
        for(int i = 0; i < n; i++) {
            mval = max(mval, max(a[i], cur + a[i]));
            cur = max(0ll, cur + a[i]);
        }
        cout << mval << endl;
    } else {
        ll cur = 0ll;
        ll curused = 0ll;
        ll mval = max(a[0] - b[0], a[0] + b[0]);
        for(int i = 0; i < n; i++) {
            // mval = max(mval, max(max(a[i] + b[i], cur + a[i] + b[i]), max(a[i] - b[i], cur + a[i] - b[i])));
            mval = max(mval, max(max(max(a[i] + b[i], cur + a[i] + b[i]), max(a[i] - b[i], cur + a[i] - b[i])), curused + a[i]));
            ll prevcur = cur;
            cur = max(0ll, cur + a[i]);
            // curused = max(0ll, cur + a[i]);
            // cur = max(0ll, cur + a[i]);
            curused = max(0ll, max(curused + a[i], max(prevcur + a[i] + b[i], prevcur + a[i] - b[i])));
            // debug(curused);
        }
        cout << mval << endl;
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
