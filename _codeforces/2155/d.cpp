/*
Problem link: https://codeforces.com/contest/2155/problem/D
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
get one battery which doesn't work: battery 1
pair up rest, if all fail, test 1st of all pairs with 

k(k + 1) / 2 * (n / k) = n(k + 1) / 2
*/

int query(int a, int b) {
    cout << a << " " << b << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int ret = query(i, j);
            if (ret == 1) return;
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
