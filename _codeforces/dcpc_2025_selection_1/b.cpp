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


void solve() {
    int n; cin >> n;
    map<string, int> m;
    vector<vector<string>> a(3, vector<string>{});

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            string x; cin >> x;
            a[i].push_back(x);
            m[x]++;
        }
    }

    for(int i = 0; i < 3; i++) {
        int ans = 0;
        for(string s : a[i]) {
            if (m[s] == 1) {
                ans += 3;
            } else if (m[s] == 2) {
                ans++;
            }
        }
        cout << ans << " ";
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
