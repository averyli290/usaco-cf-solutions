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
3+4x+r=k(3+4y)
r=3(k-1)+4(y-x)
r=3k+1 (mod 2)
if k odd, done

3+4x+r=k(1+4y)
r=k-3+4ky-4x
r=3k+1 (mod 2)
if k odd, done
*/


void solve() {
    int n; cin >> n;
    vi v(n);
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x;
        if (x % 2 == 0) {
            if (a == 0) a = x;
            else b = x;
        }
    }
    if (b != 0) {
        cout << a << " " << b << endl;
        return;
    }
    if (v[0] == 1) {
        cout << v[0] << " " << v[1] << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if ((v[j] % v[i]) % 2 == 0) {
                cout << v[i] << " " << v[j] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
