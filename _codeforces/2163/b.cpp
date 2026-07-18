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
*/


void solve() {
    int n; cin >> n;
    vi p(n);
    int nidx;
    int oidx;
    for(int i = 0; i < n ;i++) {
        cin >> p[i];
        if (p[i] == 1) oidx = i + 1;
        else if (p[i] == n) nidx = i + 1;
    }
    string s; cin >> s;
    if (s[0] == '1' || s[n - 1] == '1') {
        cout << "-1" << endl;
        return;
    }
    for(int i = 0; i < n ;i++) {
        if ((p[i] == n || p[i] == 1) && s[i] == '1') {
            cout << "-1" << endl;
            return;
        }
    }
    cout << 5 << endl;
    cout << min(oidx, nidx) << " " << max(oidx, nidx) << endl;
    cout << oidx << " " << n << endl;
    cout << nidx << " " << n << endl;
    cout << 1 << " " << oidx << endl;
    cout << 1 << " " << nidx << endl;
    
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
