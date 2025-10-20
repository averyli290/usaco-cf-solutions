/*
Problem link: 
*/

//#include <bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

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
    vector<int> a;
    map<int, int> mp;
    for(int i = 0; i < n; i++)  {
        int x; cin >> x;
        a.push_back(x);
        mp[x]++;
    }

    sort(all(a));

    int cur = 0;
    int minval = 1E7;
    while (mp[cur] > 0) {
        minval = min(minval, mp[cur]);
        cur++;
    }
    cout << cur << endl;
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
