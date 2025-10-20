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


/*
b_i - b_{i-1}

*/

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  {
        cin >> a[i];
    }

    vector<int> b(n, 0);
    b[0] = 1;
    int cur = 2;
    for(int i = 1; i < n; i++) {
        ll diff = a[i] - a[i - 1];
        if (diff <= i && i - diff >= 0 && i - diff < n) {
            b[i] = b[i - diff];
        } else {
            b[i] = cur;
            cur++;
        }
    }
    
    for(int v : b) {
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
