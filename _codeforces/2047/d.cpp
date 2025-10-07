/*
Problem link: https://codeforces.com/contest/2047/problem/D
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
make sure to check 

10 3 8 2 9
10 8 2 9 4
10 2 9 4 9
10 2 4 9 10
2 4 9 10 11

10 3 8 2 9
10 8 2 9 4
10 2 9 4 9
10 2 4 9 10
2 4 9 10 11
*/

void solve() {
    int n; cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b;
    int curmin = a[0];
    if (a[0] > *min_element(all(a))) {
        b.push_back(a[0] + 1);
    }
    for(int i = 1; i < n; i++) {
        if (a[i] > curmin + 1) {
            b.push_back(a[i] + 1);
        } else {
            b.push_back(a[i]);
        }
        curmin = min(curmin, a[i]);
    }

    sort(all(b));
    for(int v : b) {
        cout << v << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
