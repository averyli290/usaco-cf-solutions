/*
Problem link: https://codeforces.com/contest/2183/problems/B
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
    map<int, int> mp;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        mp[a[i]]++;
    }
    int curmex = 0;
    while(mp[curmex] > 0) curmex++;
    int maxmex = curmex;
    for(int i = k; i < n; i++) {
        mp[a[i - k]]--;
        mp[a[i]]++;
        curmex = 0;
        while(mp[curmex] > 0) curmex++;
        // if (mp[a[i - k]] == 0 && a[i - k] < curmex) curmex = a[i - k];
        // else if (a[i] == curmex) {
        //     while(mp[curmex] > 0) curmex++;
        // }
        maxmex = max(curmex, maxmex);
    }
    debug(maxmex);
    debug(k - 1);
    cout << min(maxmex, k - 1) << endl;
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
