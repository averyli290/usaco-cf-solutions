/*
Problem link: https://codeforces.com/contest/2056/problem/C
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
    vector<string> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vi ans;
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1, false);
    vis[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            if (arr[cur - 1][i] && !vis[i + 1]) {
                q.push(i + 1);
                vis[i + 1] = true;
            }
        }
        int idx = 0;
        while(idx < sz(ans) && arr[cur - 1][ans[idx] - 1] == '1') {
            idx++;
        }
        ans.insert(ans.begin() + idx, cur);
    }
    for(int i : ans) {
        cout << i << " ";
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
