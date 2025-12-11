/*
Problem link: https://codeforces.com/contest/2173/problem/C
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
    int n, k; cin >> n >> k;
    set<int> left;

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        left.insert(a[i]);
    }
    set<int> aa(all(a));
    sort(all(a));
    bool works = true;
    int ans = 0;
    vi b;
    for(int i = 0; i < n; i++) {
        if(left.count(a[i]) > 0) {
            for(int j = a[i]; j <= k; j+=a[i]) {
                if (left.count(j) > 0) {
                    left.erase(j);
                }
                if (aa.count(j) == 0){
                    works = false;
                    break;
                }
            }
            ans += 1;
            b.push_back(a[i]);
        }
        if (!works) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
    for(int x : b) {
        cout << x << " ";
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
