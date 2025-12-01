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
O(n) because only n indices
*/

void solve() {
    int n, d; cin >> n >> d;
    vi a(n);
    map<int, vi> idxs;
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        idxs[a[i]].push_back(i);
    }

    for(int ans = 0; ans < n; ans++) {
        if (idxs.count(ans) == 0) {
            cout << ans << endl;
            return;
        } else {
            bool good = true;
            int invalid_start = -1000000; // [i_s, i_s + d) is current invalid range, i_s + d is start of next valid
            vi cur = idxs[ans];

            int i = 0;
            while (i < sz(cur)) {
                if (cur[i] >= invalid_start && cur[i] < invalid_start + d) {
                    good = false;
                    break;
                }
                int j = i + 1;
                while(j < sz(cur) && cur[j] - cur[i] + 1 <= d) j++;
                int start = max(0, max(invalid_start + d, cur[j - 1] - (d - 1))); // has to start at at least 0 and at least i_s + d
                invalid_start = start + d;
                i = j;
            }
            if (good) {
                cout << ans << endl;
                return;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    
}
