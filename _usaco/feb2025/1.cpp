/*
Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1494
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
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi suffmax(n);
    suffmax[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suffmax[i] = max(a[i], suffmax[i + 1]);
    }
    vi ans;
    for(int i = 0; i < n; i++) {
        // shouldn't just take the first one for which this is true, want the take the one
        // which maximizes the number of suffix maximums
        // gotta fix this if statement/algo somehow, compute over all possible where a[i] < suffmax
        // or find the one that maximizes in O(n)
        if (a[i] < suffmax[i]) {
            vi a2;
            bool skipped = false;
            // debug(i);
            for(int j = n - 1; j > i; j--) {
                if (a[j] == suffmax[i]) {
                    a.erase(a.begin() + j);
                    break;
                }
            }
            for(int j = i; j < n - 1; j++) a2.push_back(a[j]);
            vi suffmax2(sz(a2));
            // cout << "a2: ";
            // for(int v : a2) {
            //     cout << v << " ";
            // }
            // cout << endl;
            suffmax2[sz(a2) - 1] = a2[sz(a2) - 1];
            for(int j = sz(a2) - 2; j >= 0; j--) {
                suffmax2[j] = max(a2[j], suffmax2[j + 1]);
            }

            // debug(suffmax[i]);
            ans.push_back(suffmax[i]);
            
            int j = 0;
            while(j < sz(a2)) {
                if (a2[j] == suffmax2[j]) ans.push_back(a2[j]);
                j++;
            }
            break;
        } else {
            ans.push_back(a[i]);
        }
    }
    for(int i = 0; i < sz(ans); i++) {
        cout << ans[i] << ((i < sz(ans) - 1) ? " " : "");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        if (t > 0) cout << endl;
    }
    
}
