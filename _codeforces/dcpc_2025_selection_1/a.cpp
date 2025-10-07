/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/637922/problem/A
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
    int r, b; cin >> r >> b;
    int ct = r / (b + 1);
    int rem = r - (ct * (b + 1));
    string ans = "";
    for(int i = 0; i <= b; i++) {
        for(int j = 0; j < ct; j++) {
            ans += "R";
        }
        if (rem > 0) {
            ans += "R";
            rem--;
        }
        if (i < b) {
        ans += "B";
        }
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
