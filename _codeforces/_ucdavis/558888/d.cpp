/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/558888/problem/D
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
want to take last pile entirely
force one before to take size 1
*/

void solve() {
    int n; cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    if (sz(s) == 1) {
        cout << "Alice" << endl;
        return;
    }
    int ans = 0;
    vector<int> a(all(s));
    a.insert(a.begin(), 0)
    //debug_vector(a, sz(a));
    for(int i = 0; i < sz(a) - 1; i++) {
        if (a[i] - a[i] == 1) ans++;
        else break;
    }
    if (ans % 2 == 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;

// 1 3 9 7 4 2 100 A
// 1 2 3 4 7 9 100 A
// 1 2 3 6 8 99 B
// 1 2 5 7 98 A
// 1 4 6 97 B
// 3 5 96 A
// 1 3 94 B
// 2 93 A
// 1 92 B
// 91 A


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
