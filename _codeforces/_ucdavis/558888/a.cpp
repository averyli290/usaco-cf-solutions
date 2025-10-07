/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/558888/problem/A
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
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        string s; int x; cin >> s >> x;
        mp[s] = x;
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        mp[s]--;
    }
    for(auto& [k, v] : mp) {
        if (v > 0) {
            cout << k << endl;
            return;
        }
    }
    cout << "NO KPOP FOR VADER" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
