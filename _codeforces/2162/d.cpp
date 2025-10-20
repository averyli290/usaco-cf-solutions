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
2,1,3,4
2,2,4,5
*/

int query(int t, pii rang) {
    auto [l, r] = rang;
    cout << t << " " << l << " " << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    int l = 0;
    int r = n;
    int rans = n+1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        pii rang = pii{m, n};
        int a = query(1, rang);
        int b = query(2, rang);
        if (a == b) {
            rans = m;
            r = m - 1;
        } else {
            l = m;
        }
    }
    int a = query(1, pii{1, rans - 1});
    int b = query(2, pii{1, rans - 1});
    int lans = rans - (b - a);
    cout << "! " << lans << " " << rans - 1 << endl;
    cout.flush();
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
