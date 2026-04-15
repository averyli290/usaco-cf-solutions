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
2 3 1 4 5
*/

void solve() {
    int n; cin >> n;
    vi p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int min_elt=1000000;
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < n; i++) {
        min_elt = min(min_elt, p[i]);
        if (i < n - 1 && min_elt == n - i) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    set<int> available;
    int max_enc = 0;
    for(int i = n-1; i >= 0; i--) {
        int cur = p[i];
        if (cur > max_enc) {
            if (!available.empty()) 
            cout << *available.begin() << " " << cur << endl;
            for (int j = max_enc + 1; j < cur; j++) {
                available.insert(j);
                cout << j << " " << cur << endl;
            }
            max_enc = cur;

        } else {
            available.erase(cur);
        }
    }

    // vector<bool> vis(n + 1, false);
    // set<int> available;
    // for(int i = 1; i <= n; i++) available.insert(i);
    // for(int i = n-1; i >= 0; i--) {
    //     available.erase(p[i]);
    //     if (vis[p[i]]) continue;
    //     vis[p[i]] = true;
    //     int vis_ct = 0;
    //     for(auto val : available) {
    //         if (val > p[i]) break;
    //         adj[val].push_back(p[i]);
    //         if (vis[val]) {
    //             break;
    //         }
    //         vis[val] = true;
    //     }
    // }

    // cout << "Yes" << endl;
    // for(int i = 1; i <= n; i++) {
    //     for(int neig : adj[i]) {
    //         cout << min(i, neig) << " " << max(i, neig) << endl;
    //     }
    // }
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
